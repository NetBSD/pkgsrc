# $NetBSD: Makefile,v 1.73 2017/08/07 17:56:13 jlam Exp $

DISTNAME=	open-vm-tools-10.1.5-5055683
PKGNAME=	open-vm-tools-10.1.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/vmware/open-vm-tools/releases/download/stable-10.1.5/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/vmware/open-vm-tools
COMMENT=	Open source VMware tools
LICENSE=	gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

GCC_REQD+=	4.8
BUILDLINK_TRANSFORM.NetBSD+=	rm:-Werror

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c gnu++11
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake

PLIST_SRC=	PLIST.common

CONFIGURE_ARGS+=		--disable-unity --sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=		--disable-vgauth
CONFIGURE_ARGS+=		--disable-grabbitmqproxy
CONFIGURE_ARGS+=		--disable-docs # Requires doxygen

INSTALLATION_DIRS+=		share/examples/vmware-tools

PKG_SYSCONFSUBDIR=		vmware-tools
EGDIR=				${PREFIX}/share/examples/vmware-tools
CONF_FILES_PERMS+=		${EGDIR}/poweroff-vm-default ${PKG_SYSCONFDIR}/poweroff-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/poweron-vm-default ${PKG_SYSCONFDIR}/poweron-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/resume-vm-default ${PKG_SYSCONFDIR}/resume-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/statechange.subr ${PKG_SYSCONFDIR}/statechange.subr ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/suspend-vm-default ${PKG_SYSCONFDIR}/suspend-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
RCD_SCRIPTS=			vmtools

SUBST_CLASSES+=			fix-etc-path
SUBST_STAGE.fix-etc-path=	pre-configure
SUBST_MESSAGE.fix-etc-path=	Fixing PREFIX
SUBST_FILES.fix-etc-path+=	lib/guestApp/guestApp.c
SUBST_FILES.fix-etc-path+=	lib/procMgr/procMgrPosix.c
SUBST_VARS.fix-etc-path+=	PREFIX

pre-configure:
	cd ${WRKSRC} && autoreconf -f

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=unused-local-typedef
CWRAPPERS_APPEND.cc+=	-Wno-error=unused-local-typedef
.elif !empty(PKGSRC_COMPILER:Mgcc) && empty(CC_VERSION:U:Mgcc-[1-3].*) && empty(CC_VERSION:U:Mgcc-4.[0-7]*)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=unused-local-typedefs -Wno-error=unused-but-set-variable
CWRAPPERS_APPEND.cc+=	-Wno-error=unused-local-typedefs -Wno-error=unused-but-set-variable
.endif

.include "../../archivers/libmspack/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/xml-security-c/buildlink3.mk"

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
