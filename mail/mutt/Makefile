# $NetBSD: Makefile,v 1.144.2.3 2006/12/11 13:55:22 ghen Exp $

DISTNAME=		mutt-1.4.2.2i
PKGREVISION=		3
PKGNAME=		${DISTNAME:C/i$//}
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}			\
			--with-docdir=${PREFIX}/share/doc/mutt		\
			--without-included-gettext			\
			--enable-pop					\
			--enable-imap
MAKE_ENV+=		CHGRP=${CHGRP:Q}

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-wc-funcs
.endif

.if ${LOWER_OPSYS} == "irix5.3"
CONFIGURE_ENV+=		ac_cv_header_inttypes_h=no
.endif

SUBST_CLASSES+=		gpg
SUBST_MESSAGE.gpg=	Fixing path to GnuPG binary.
SUBST_STAGE.gpg=	post-patch
SUBST_FILES.gpg=	contrib/gpg.rc
SUBST_SED.gpg=		-e "s,/usr/bin/gpg,gpg,g"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in manual page.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	doc/mutt.man
SUBST_SED.paths=	-e "s,/usr/local/doc/mutt/,${DOCDIR}/,g"
SUBST_SED.paths+=	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"
SUBST_SED.paths+=	-e "s,/usr/local/,${PREFIX}/,g"

.if ${OPSYS} == "Interix"
SUBST_CLASSES+=		mgroup
SUBST_MESSAGE.mgroup=	Configuring mail group.
SUBST_STAGE.mgroup=	post-patch
SUBST_FILES.mgroup=	configure
SUBST_SED.mgroup=	-e "s,DOTLOCK_GROUP='mail',DOTLOCK_GROUP='+Administrators',"

CPPFLAGS+=		-D__BROKEN_INTERIX_FORK
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

INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

.if exists(${WRKSRC}/mutt_dotlock)
PLIST_SUBST+=		MUTT_DOTLOCK=
.else
PLIST_SUBST+=		MUTT_DOTLOCK="@comment "
.endif
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

# Pre-create some directories and symlinks used during the installation
# process.
#
pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${RM} -f ${DOCDIR}/samples
	${LN} -sf ${EGDIR} ${DOCDIR}/samples

post-install:
.if (${PKG_INSTALLATION_TYPE} == "pkgviews")
	${MV} ${PREFIX}/man/man5/mutt-mbox.5 ${PREFIX}/man/man5/mbox.5
.endif

.include "../../mk/bsd.pkg.mk"
