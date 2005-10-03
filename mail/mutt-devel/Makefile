# $NetBSD: Makefile,v 1.38 2005/10/03 14:16:53 tonio Exp $

DISTNAME=		mutt-1.5.11
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

BUILD_USES_MSGFMT=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
REPLACE_PERL=		smime_keys */*.pl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}			\
			--with-docdir=${PREFIX}/share/doc/mutt		\
			--without-included-gettext			\
			--enable-pop					\
			--enable-imap
MAKE_ENV+=		CHGRP=${CHGRP}

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

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
DOCDIR=			${PREFIX}/share/doc/mutt
EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
CONF_FILES+=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types
FILES_SUBST+=		DOCDIR=${DOCDIR}

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

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
