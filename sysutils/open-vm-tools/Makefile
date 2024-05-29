# $NetBSD: Makefile,v 1.129 2024/05/29 16:34:29 adam Exp $

OVTVER=		12.4.0
DISTNAME=	open-vm-tools-${OVTVER}-23259341
PKGNAME=	open-vm-tools-${OVTVER}
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=vmware/}
GITHUB_RELEASE=	stable-${OVTVER}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/vmware/open-vm-tools
COMMENT=	Open source VMware tools
LICENSE=	gnu-lgpl-v2.1

BROKEN_EXCEPT_ON_PLATFORM=	*-*-aarch64 *-*-i386 *-*-x86_64

# Workaround for glib2-2.68.0 c++ fallout.
CXXFLAGS+=	-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_66

BUILDLINK_TRANSFORM+=	rm:-Werror

USE_LANGUAGES=		c gnu++11
USE_CXX_FEATURES+=	c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-docs # Requires doxygen
CONFIGURE_ARGS+=	--disable-vgauth
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS+=	share/examples/vmware-tools

PKG_SYSCONFSUBDIR=	vmware-tools
EGDIR=			${PREFIX}/share/examples/vmware-tools
CONF_FILES_PERMS+=	${EGDIR}/poweroff-vm-default ${PKG_SYSCONFDIR}/poweroff-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=	${EGDIR}/poweron-vm-default ${PKG_SYSCONFDIR}/poweron-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=	${EGDIR}/resume-vm-default ${PKG_SYSCONFDIR}/resume-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=	${EGDIR}/statechange.subr ${PKG_SYSCONFDIR}/statechange.subr ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=	${EGDIR}/suspend-vm-default ${PKG_SYSCONFDIR}/suspend-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=	${EGDIR}/tools.conf ${PKG_SYSCONFDIR}/tools.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644
RCD_SCRIPTS=		vmtools

SUBST_CLASSES+=			fix-etc-path
SUBST_STAGE.fix-etc-path=	pre-configure
SUBST_MESSAGE.fix-etc-path=	Fixing PREFIX
SUBST_FILES.fix-etc-path+=	lib/guestApp/guestApp.c
SUBST_FILES.fix-etc-path+=	lib/procMgr/procMgrPosix.c
SUBST_VARS.fix-etc-path+=	PREFIX

CHECK_PORTABILITY_SKIP+=	scripts/solaris/network

pre-configure:
	cd ${WRKSRC} && autoreconf -f -i

post-install:
	mv ${DESTDIR}${PKG_SYSCONFDIR}/tools.conf.example \
		${DESTDIR}${EGDIR}/tools.conf

.include "options.mk"
.include "../../archivers/libmspack/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
