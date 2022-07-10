# $NetBSD: Makefile,v 1.37 2022/07/10 19:13:22 wiz Exp $

DISTNAME=		mpc-0.34
CATEGORIES=		audio
MASTER_SITES=		https://www.musicpd.org/download/mpc/0/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		https://musicpd.org/
COMMENT=		Command-line client for musicpd
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
# added as of 0.34. not sure why, but meson complains if it's missing
TOOL_DEPENDS+=		rsync-[0-9]*:../../net/rsync

USE_TOOLS+=		pkg-config

LDFLAGS+=		${BUILDLINK_LDADD.iconv}

SUBST_CLASSES+=		sphinx
SUBST_STAGE.sphinx=	pre-configure
SUBST_FILES.sphinx=	meson.build
SUBST_MESSAGE.sphinx=	Fixing sphinx binary name.
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build-${PYVERSSUFFIX},"

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.libmpdclient+=	libmpdclient>=2.16
.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
