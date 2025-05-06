# $NetBSD: Makefile,v 1.22 2025/05/06 20:35:02 vins Exp $

DISTNAME=	newt-0.52.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/newt/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pagure.io/newt
COMMENT=	Windowing toolkit based on libslang2
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		automake aclocal autoconf \
			gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libnewt.pc.in

PY_PATCHPLIST=		yes

CONFIGURE_ENV+=		ac_cv_c_tclconfig=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-python=${PYVERSSUFFIX:Q}

MAKE_ENV=		PCFLAGS=${CFLAGS:Q}

pre-configure:
	cd ${WRKSRC}; \
	aclocal && autoconf

SUBST_CLASSES+=		inst-po
SUBST_STAGE.inst-po=	pre-build
SUBST_FILES.inst-po=	po/Makefile
SUBST_VARS.inst-po=	INSTALL PKGLOCALEDIR

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
