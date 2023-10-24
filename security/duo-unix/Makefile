# $NetBSD: Makefile,v 1.7 2023/10/24 22:10:47 wiz Exp $
#

DISTNAME=	duo_unix-1.11.4
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://dl.duosecurity.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.duosecurity.com/
COMMENT=	Duo two-factor authentication for Unix systems
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	lib/libduo.pc.in

.include "options.mk"

CONFIGURE_ARGS+=	--enable-lib64=no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/duo-unix

INSTALLATION_DIRS=	share/examples/duo-unix

CONF_FILES_PERMS+=	share/examples/duo-unix/login_duo.conf	\
			${PKG_SYSCONFDIR}/login_duo.conf	\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0400

SPECIAL_PERMS+=		sbin/login_duo ${SETUID_ROOT_PERMS}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	login_duo/login_duo.8 pam_duo/pam_duo.8
SUBST_SED.paths=	-e 's,/etc/duo,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/usr/local,${PREFIX},g'

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
