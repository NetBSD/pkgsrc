# $NetBSD: Makefile,v 1.66 2024/05/29 16:33:59 adam Exp $

DISTNAME=	netatalk-2.3.2
PKGNAME=	${DISTNAME:C/-/22-/}
PKGREVISION=	2
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_GITHUB:=Netatalk/}Netatalk/releases/download/${DISTNAME:C/\./-/g}/
EXTRACT_SUFX=	.tar.xz

#PATCHFILES=	patch-adv1tov2.c
PATCH_SITES=	http://svn.macosforge.org/repository/macports/trunk/dports/net/netatalk/files/ \
		http://mirror.lug.udel.edu/pub/macports/trunk/dports/net/netatalk/files/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://netatalk.io/
COMMENT=	Netatalk appletalk file and print services
LICENSE=	gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config perl:run
GNU_CONFIGURE=		yes

# https://mail-index.netbsd.org/pkgsrc-users/2021/10/01/msg034512.html
CHECK_RELRO_SKIP+=	libexec/netatalk/uams/*.a

BUILDLINK_TRANSFORM+=	l:db48:${BDB_TYPE}

PKG_SYSCONFSUBDIR=	netatalk
EGDIR=			${PREFIX}/share/examples/netatalk
CONF_FILES=		${EGDIR}/AppleVolumes.default ${PKG_SYSCONFDIR}/AppleVolumes.default
CONF_FILES+=		${EGDIR}/AppleVolumes.system ${PKG_SYSCONFDIR}/AppleVolumes.system
CONF_FILES+=		${EGDIR}/afpd.conf ${PKG_SYSCONFDIR}/afpd.conf
CONF_FILES+=		${EGDIR}/atalkd.conf ${PKG_SYSCONFDIR}/atalkd.conf
CONF_FILES+=		${EGDIR}/netatalk.conf ${PKG_SYSCONFDIR}/netatalk.conf
CONF_FILES+=		${EGDIR}/papd.conf ${PKG_SYSCONFDIR}/papd.conf

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
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
SUBST_FILES.paths=	etc/psf/etc2ps.sh
SUBST_SED.paths=	-e 's,^\(DVIPS="*\)/usr\(/bin\),\1${PREFIX}\2,'

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-netbsd
RCD_SCRIPTS=		afpd atalkd papd timelord cnid_metad
.  for f in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${f}=	${WRKSRC}/distrib/initscripts/${f}
.  endfor
.endif

PLIST_VARS+=		ea
.if ${OPSYS} == "SunOS" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || \
	(${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 070000) || \
	${OPSYS} == "FreeBSD"
PLIST.ea=		yes
.endif

# ea
PRINT_PLIST_AWK+=	{ gsub(/^bin\/ad$$/, "$${PLIST.ea}&"); }

# pam
PRINT_PLIST_AWK+=	{ gsub(/^libexec\/netatalk\/uams\/.+_pam\.la$$/, "$${PLIST.pam}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^share\/examples\/netatalk\/netatalk\.pam$$/, "$${PLIST.pam}&"); }

# ldap
PRINT_PLIST_AWK+=	{ gsub(/^share\/examples\/netatalk\/afp_ldap\.conf$$/, "$${PLIST.ldap}&"); }

# gssapi
PRINT_PLIST_AWK+=	{ gsub(/^libexec\/netatalk\/uams\/.+_gss\.la$$/, "$${PLIST.gssapi}&"); }

CHECK_SSP_SKIP+=	libexec/netatalk/uams/*.a

.include "options.mk"

INSTALLATION_DIRS=	libexec/psffilters

post-install:
.if !empty(PKG_OPTIONS:Mpam)
	${INSTALL_DATA} ${WRKSRC}/config/pam/netatalk.pam ${DESTDIR}${EGDIR}
.endif

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
