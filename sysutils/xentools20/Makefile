# $NetBSD: Makefile,v 1.1.1.1 2005/03/07 15:59:08 bouyer Exp $
#

DISTNAME=		xen-2.0.3-src
PKGNAME=		xentools20-2.0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cl.cam.ac.uk/Research/SRG/netos/xen/downloads/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
#DISTFILES+=		netbsd-xen-kernel-headers-040508.tar.gz

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.netbsd.org/Ports/xen/
COMMENT=		Userland Tools for Xen

DEPENDS+=		${PYPKGPREFIX}-twisted*:../../net/py-twisted

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}/xen-2.0/tools

PKG_SYSCONFSUBDIR?=	xc20
USE_PKGINSTALL=		yes
EGDIR=			${PREFIX}/share/examples/${PKGNAME_NOREV}
CONF_FILES=		${EGDIR}/defaults ${PKG_SYSCONFDIR}/defaults
CONF_FILES+=		${EGDIR}/democd ${PKG_SYSCONFDIR}/democd
CONF_FILES+=		${EGDIR}/netbsd ${PKG_SYSCONFDIR}/netbsd

USE_GNU_TOOLS+=		make
MAKE_ENV+=		EGDIR="${EGDIR}"
MAKE_ENV+=		MV="${MV}" PYTHON="${PYTHONBIN}" SED="${SED}"
PYTHON_VERSIONS_ACCEPTED= 24pth 23pth 22pth
PY_PATCHPLIST=		yes
PYTHON_PATCH_SCRIPTS=	python/xen/util/console_client.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/server/SrvServer.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/XendClient.py
PYTHON_PATCH_SCRIPTS+=	python/xen/xend/sxp.py
PYTHON_PATCH_SCRIPTS+=	xfrd/xfrdClient.py
PYTHON_PATCH_SCRIPTS+=	misc/xensymoops
PYTHON_PATCH_SCRIPTS+=	misc/xencons
PYTHON_PATCH_SCRIPTS+=	misc/xm
PYTHON_PATCH_SCRIPTS+=	misc/xensv
PYTHON_PATCH_SCRIPTS+=	misc/netfix
PYTHON_PATCH_SCRIPTS+=	misc/xend
PYTHON_PATCH_SCRIPTS+=	xentrace/xentrace_format
USE_BUILDLINK3=		yes

SUBST_CLASSES=          paths
SUBST_STAGE.paths=      pre-configure
SUBST_FILES.paths=      python/xen/xend/server/SrvDaemon.py
SUBST_FILES.paths+=	python/xen/xend/XendDomainInfo.py
SUBST_FILES.paths+=	python/xen/sv/Daemon.py
SUBST_SED.paths=        -e "s|/usr/sbin|${PREFIX}/sbin|g"
SUBST_MESSAGE.paths=    "Fixing hardcoded paths."

pre-build:
	${MKDIR} ${WRKSRC}/libxc/xen/NetBSD
	${CP} files/xenio.h ${WRKSRC}/libxc/xen/NetBSD

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
