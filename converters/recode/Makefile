# $NetBSD: Makefile,v 1.37 2023/06/06 12:40:25 riastradh Exp $

DISTNAME=	recode-3.7.14
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=rrthomas/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/recode/
COMMENT=	Convert files between character sets and usages
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

# needed only for tests, but detected at configure time
TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

# to detect cython properly, configure is only looking for unversioned cython
CONFIGURE_ENV+=	CYTHON=cython-${PYVERSSUFFIX}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes
TEST_TARGET=	check

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		yes

.include "../../lang/python/tool.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
