# $NetBSD: Makefile,v 1.52.2.1 2006/12/11 14:07:43 ghen Exp $

DISTNAME=		mutt-1.5.13
PKGREVISION=		2
CATEGORIES=		mail
MUTT_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/
MASTER_SITES=		${MUTT_SITES:=devel/}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP & S/MIME support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl:run
REPLACE_PERL=		*.pl */*.pl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}		\
			--with-docdir=${PREFIX}/share/doc/mutt		\
			--without-included-gettext			\
			--enable-pop					\
			--enable-imap
MAKE_ENV+=		CHGRP=${CHGRP:Q}

.if (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--without-wc-funcs
.endif

# There is a problem using /bin/sh on old NetBSD releases, so use /bin/ksh
# there.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-5]*-*)
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

.include "options.mk"

LDFLAGS+=		${_STRIPFLAG_CC}

DOCDIR=			${PREFIX}/share/doc/mutt
EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
FILES_SUBST+=		DOCDIR=${DOCDIR:Q}
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

# Define WRKSRC explicitly so we can use its value below.
WRKSRC=			${WRKDIR}/${DISTNAME}
.if exists(${WRKSRC}/mutt_dotlock)
PLIST_SUBST+=		MUTT_DOTLOCK=
.else
PLIST_SUBST+=		MUTT_DOTLOCK="@comment "
.endif
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

# Fix some absolute paths in installed files.
post-build:
	for file in ${WRKSRC}/contrib/gpg.rc; do			\
		${MV} -f $$file $$file.save;				\
		${SED}	-e "s,/usr/bin/gpg,gpg,g"			\
			$$file.save > $$file;				\
	done
	for file in ${WRKSRC}/doc/mutt.man; do				\
		${MV} -f $$file $$file.save;				\
		${SED}	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"		\
			-e "s,/usr/local/doc/mutt/,${DOCDIR}/,g"	\
			-e "s,/usr/local/,${PREFIX}/,g"			\
			$$file.save > $$file;				\
	done

.include "../../mk/bsd.pkg.mk"
