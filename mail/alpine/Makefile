# $NetBSD: Makefile,v 1.59 2024/05/28 00:46:29 dholland Exp $

DISTNAME=	alpine-2.26
PKGREVISION=	3
CATEGORIES=	mail
# repo at https://repo.or.cz/alpine.git
MASTER_SITES=	https://alpineapp.email/alpine/release/src/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

PATCH_SITES=		https://alpineapp.email/alpine/patches/alpine-${PKGVERSION_NOREV}/
# Maildir Support
PATCHFILES+=		maildir.patch.gz
# Enhanced Fancy Thread Interface
PATCHFILES+=		fancy.patch.gz
# Justify paragraphs that contain more than one level of quoting
PATCHFILES+=		fillpara.patch.gz
# Send e-mail from the command line
PATCHFILES+=		outgoing.patch.gz
# Support accents in pico
PATCHFILES+=		WrtAcc.patch.gz
# Additional compose subcommands
PATCHFILES+=		compose.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://alpineapp.email/
COMMENT=	Program for Internet News and E-mail
LICENSE=	apache-2.0

CONFLICTS+=	pico-[0-9]*      # bin/{pico,pilot}
CONFLICTS+=	pine-[0-9]*      # bin/{rpdump,rpload}

GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=	no
BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+=	--with-ssl-certs-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+=	--with-ssl-include-dir=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-ssl-lib-dir=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+=	--with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed
CONFIGURE_ARGS+=	--with-passfile=.pine-passfile
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-system-mail-directory=${VARBASE}/spool/mail
.else
CONFIGURE_ARGS+=	--with-system-mail-directory=${VARBASE}/mail
.endif
CONFIGURE_ARGS+=	--with-debug-level=2
CONFIGURE_ARGS+=	--without-ntlm
CONFIGURE_ARGS+=	--without-npa
# disabled, for Web Alpine Support
CONFIGURE_ARGS+=	--without-tcl

.include "options.mk"

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/pine.conf \
		${PKG_SYSCONFDIR}/pine.conf

PKG_DOCS=	LICENSE NOTICE README README.maildir VERSION
PKG_DOCS+=	doc/brochure.txt doc/mailcap.unx doc/mime.types
PKG_DOCS+=	doc/tech-notes/tech-notes.txt
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

# mach/mach.h defines panic, differently.
SUBST_CLASSES.Darwin+=	panic
SUBST_STAGE.panic=	pre-configure
SUBST_MESSAGE.panic=	Renaming the panic function
SUBST_FILES.panic=	*/*.c
SUBST_FILES.panic+=	*/*/*.c
SUBST_FILES.panic+=	*/*/*/*.c
SUBST_FILES.panic+=	pith/util.h
SUBST_SED.panic+=	-e 's,panic *(,Panic(,g'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	doc/man1/alpine.1 doc/tech-notes/*.txt pith/pine.hlp
SUBST_SED.paths+=	-e "s:/usr/local/pine.conf:${PKG_SYSCONFDIR}/pine.conf:g"
SUBST_SED.paths+=	-e "s:/usr/local/lib:${PKG_SYSCONFDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/local/bin:${PREFIX}/bin:g"
SUBST_SED.paths+=	-e "s:/usr/local/ssl:${SSLDIR}:g"

SUBST_CLASSES+=		var
SUBST_STAGE.var=	pre-configure
SUBST_FILES.var=	alpine/pine-use.c doc/man1/alpine.1
SUBST_VARS.var=		VARBASE
SUBST_MESSAGE.var=	Replacing VARBASE placeholders.

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

do-install:
.for bin in \
	alpine/alpine alpine/rpdump alpine/rpload	\
		pico/pico pico/pilot
	${INSTALL_PROGRAM} ${WRKSRC}/${bin} ${DESTDIR}${PREFIX}/bin
.endfor
.for man in alpine rpdump rpload pico pilot
	${INSTALL_MAN} ${WRKSRC}/doc/man1/${man}.1	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

post-install:
	${RUN}${WRKSRC}/alpine/alpine -conf > ${DESTDIR}${EGDIR}/pine.conf
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|} ${DESTDIR}${DOCDIR}

# This must come first, or at least before gettext-tools, because the
# latter includes termcap.buildlink3.mk instead; that sets things up
# to use -ltermcap, not -lterminfo, but the package's makefile uses
# -lterminfo and then the link fails.
.include "../../mk/terminfo.buildlink3.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
