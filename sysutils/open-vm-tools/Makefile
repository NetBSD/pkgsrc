# $NetBSD: Makefile,v 1.44 2014/02/12 23:18:40 tron Exp $

DISTNAME=	open-vm-tools-2008.08.08-109361
PKGNAME=	open-vm-tools-2008.08.08.109361
PKGREVISION=	35
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=open-vm-tools/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://open-vm-tools.sourceforge.net/
COMMENT=	Open source VMware tools

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake

PLIST_SRC=	PLIST.common

CONFIGURE_ARGS+=		--disable-unity

INSTALLATION_DIRS+=		${PKG_SYSCONFDIR} share/examples/vmware-tools

PKG_SYSCONFSUBDIR=		vmware-tools
EGDIR=				${PREFIX}/share/examples/vmware-tools
CONF_FILES_PERMS+=		${EGDIR}/poweroff-vm-default ${PKG_SYSCONFDIR}/poweroff-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/poweron-vm-default ${PKG_SYSCONFDIR}/poweron-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/resume-vm-default ${PKG_SYSCONFDIR}/resume-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/suspend-vm-default ${PKG_SYSCONFDIR}/suspend-vm-default ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS+=		${EGDIR}/tools.conf ${PKG_SYSCONFDIR}/tools.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
RCD_SCRIPTS=			vmtools

pre-configure:
	cd ${WRKSRC} && autoreconf -f

.include "../../net/libdnet/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
