# $NetBSD: Makefile,v 1.1 2004/05/08 18:24:00 cl Exp $
#

PKGNAME=		xentools12
DISTNAME=		xeno-1.2-src-040418
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		netbsd-xen-kernel-headers-040508.tar.gz
CATEGORIES=		local
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/arch/xen/misc/
EXTRACT_SUFX=		.tgz

MAINTAINER=		cl@NetBSD.org
HOMEPAGE=		http://www.netbsd.org/Ports/xen/
COMMENT=		Userland Tools for Xen

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}/xeno-1.2/tools

PKG_SYSCONFSUBDIR?=	xc12
USE_PKGINSTALL=		yes
EGDIR=			${PREFIX}/share/examples/${PKGNAME_NOREV}
CONF_FILES=		${EGDIR}/defaults ${PKG_SYSCONFDIR}/defaults
CONF_FILES+=		${EGDIR}/democd ${PKG_SYSCONFDIR}/democd
CONF_FILES+=		${EGDIR}/netbsd ${PKG_SYSCONFDIR}/netbsd

USE_GNU_TOOLS+=		make
MAKE_ENV+=		EGDIR="${EGDIR}"
MAKE_ENV+=		MV="${MV}" PYTHON="${PYTHONBIN}" SED="${SED}"
PYTHON_VERSIONS_ACCEPTED= 22 22pth 23 23pth
PY_PATCHPLIST=		yes
PYTHON_PATCH_SCRIPTS=	examples/xc_dom_control.py examples/xc_dom_create.py
PYTHON_PATCH_SCRIPTS+=	examples/xc_vd_tool.py
USE_BUILDLINK3=		yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
