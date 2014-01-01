# $NetBSD: Makefile,v 1.102 2014/01/01 11:52:30 wiz Exp $

DISTNAME=	netatalk-2.2.5
#PKGREVISION=	1
PKGREVISION=	1
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}
EXTRACT_SUFX=	.tar.bz2
#PATCHFILES=	patch-adv1tov2.c
PATCH_SITES=	http://svn.macosforge.org/repository/macports/trunk/dports/net/netatalk/files/ \
		http://mirror.lug.udel.edu/pub/macports/trunk/dports/net/netatalk/files/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://netatalk.sourceforge.net/
COMMENT=	Netatalk appletalk file and print services
LICENSE=	gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_OLD_DES_API=	yes
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=	l:db48:${BDB_TYPE}

PKG_SYSCONFSUBDIR=	netatalk
EGDIR=		${PREFIX}/share/examples/netatalk
CONF_FILES=	${EGDIR}/AppleVolumes.default ${PKG_SYSCONFDIR}/AppleVolumes.default
CONF_FILES+=	${EGDIR}/AppleVolumes.system ${PKG_SYSCONFDIR}/AppleVolumes.system
CONF_FILES+=	${EGDIR}/afpd.conf ${PKG_SYSCONFDIR}/afpd.conf
CONF_FILES+=	${EGDIR}/atalkd.conf ${PKG_SYSCONFDIR}/atalkd.conf
CONF_FILES+=	${EGDIR}/netatalk.conf ${PKG_SYSCONFDIR}/netatalk.conf
CONF_FILES+=	${EGDIR}/papd.conf ${PKG_SYSCONFDIR}/papd.conf

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--enable-netbsd
CONFIGURE_ARGS+=	--enable-overwrite
CONFIGURE_ARGS+=	--enable-timelord
CONFIGURE_ARGS+=	--enable-ddp
CONFIGURE_ARGS+=	--enable-quota
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/libexec/netatalk
CONFIGURE_ARGS+=	--with-pkgconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-message-dir=${PKG_SYSCONFDIR}/msg
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/netatalk
CONFIGURE_ARGS+=	--with-uams-path=${PREFIX}/libexec/netatalk/uams
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
CONFIGURE_ARGS+=	--with-ssl-dir=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/psf/etc2ps.sh distrib/initscripts/Makefile.in
SUBST_SED.paths=	-e "s,^\\(DVIPS=\\)\\(/usr/local/tex\\)\\(/bin\\),\\1${PREFIX}\\3,"

PLIST_VARS+=		rcd
.if ${OPSYS} == "NetBSD"
RCD_SCRIPTS=		afpd atalkd papd timelord cnid_metad
.  for f in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${f}=	${WRKSRC}/distrib/initscripts/${f}
.  endfor
PLIST.rcd=		yes
.endif

PLIST_VARS+=		ea
.if ${OPSYS} == "SunOS" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || \
	(${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-6].[0-8]*))
PLIST.ea=		yes
.endif

PLIST_VARS+=		acl
.if ${OPSYS} == "SunOS" || ${OPSYS} == "HPUX" || ${OPSYS} == "IRIX" || \
	${OPSYS} == "AIX" || ${OPSYS} == "OSF1"
PLIST.acl=		yes
CONF_FILES+=	${EGDIR}/afp_ldap.conf ${PKG_SYSCONFDIR}/afp_ldap.conf
.endif

.include "options.mk"

INSTALLATION_DIRS=	libexec/psffilters

.if !empty(PKG_OPTIONS:Mpam)
post-install:
	${INSTALL_DATA} ${WRKSRC}/config/pam/netatalk.pam ${DESTDIR}${EGDIR}
.endif

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
