# $NetBSD: Makefile,v 1.16 2016/12/06 15:13:20 ryoon Exp $

DISTNAME=	liborcus-0.11.2
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	converters
MASTER_SITES=	http://kohei.us/files/orcus/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://gitlab.com/orcus/orcus
COMMENT=	Import filter library for spreadsheet documents (0.10 branch)
LICENSE=	mpl-2.0

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python pkg-config file name
SUBST_FILES.fix-python+=        configure
SUBST_VARS.fix-python+=		PYVERSSUFFIX

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=			gmake pkg-config
PYTHON_VERSIONS_INCOMPATIBLE=	27
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}/lib
CONFIGURE_ARGS+=	--with-boost-system=boost_system
CONFIGURE_ARGS+=	--disable-spreadsheet-model
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--disable-python

PKGCONFIG_OVERRIDE+=	liborcus.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/mdds1.2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
#.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
