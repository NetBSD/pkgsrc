# $NetBSD: Makefile,v 1.19 2019/11/03 10:18:28 rillig Exp $

DISTNAME=	newt-0.52.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/newt/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pagure.io/newt
COMMENT=	Windowing toolkit based on libslang2
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		automake gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libnewt.pc.in

PY_PATCHPLIST=		yes
PYTHON_VERSIONS_ACCEPTED= 27

pre-configure:
	cd ${WRKSRC}; \
	aclocal && autoconf

SUBST_CLASSES+=		inst-po
SUBST_STAGE.inst-po=	pre-build
SUBST_FILES.inst-po=	po/Makefile
SUBST_VARS.inst-po=	INSTALL PKGLOCALEDIR

.include "../../devel/libslang2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
