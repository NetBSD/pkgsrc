# $NetBSD: Makefile,v 1.167 2014/02/12 23:18:08 tron Exp $

DISTNAME=		mutt-1.4.2.3
PKGREVISION=		7
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP support
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}		\
			--with-docdir=${PREFIX}/share/doc/mutt		\
			--without-included-gettext			\
			--enable-external-dotlock			\
			--enable-pop					\
			--enable-imap
MAKE_ENV+=		CHGRP=${CHGRP:Q}

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
# Force sendmail to /usr/sbin to avoid postfix's
# ${LOCALBASE}/sbin/sendmail.  Should be enabled on all platforms which
# support mailwrapper.
CONFIGURE_ENV+=		SENDMAIL=/usr/sbin/sendmail
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--without-wc-funcs
.endif

.if !empty(MACHINE_PLATFORM:MIRIX-5.3-*)
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

SPECIAL_PERMS+=		bin/mutt_dotlock ${REAL_ROOT_USER} mail 2551
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

# Pre-create some directories and symlinks used during the installation
# process.
#
pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${RM} -f ${DESTDIR}${DOCDIR}/samples
	${LN} -sf ${DESTDIR}${EGDIR} ${DESTDIR}${DOCDIR}/samples

post-install:
.if (${PKG_INSTALLATION_TYPE} == "pkgviews")
	${MV} ${PREFIX}/${PKGMANDIR}/man5/mutt-mbox.5 ${PREFIX}/${PKGMANDIR}/man5/mbox.5
.endif

.include "../../mk/bsd.pkg.mk"
