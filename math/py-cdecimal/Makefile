# $NetBSD: Makefile,v 1.1 2013/08/15 14:23:01 richard Exp $

DISTNAME=	cdecimal-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bytereef.org/mpdecimal/
COMMENT=	Arbitrary precision decimal floating point arithmetic
LICENSE=	2-clause-bsd

NO_CONFIGURE=	YES

USE_TOOLS+=	gmake
USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

.include "../../lang/python/pyversion.mk"

PYTHON_VERSIONS_INCLUDE_3X=	YES
.if ${_PYTHON_VERSION} >= 33 
PKG_FAIL_REASON+=	"${DISTNAME} is obsoleted by the builtin \`decimal\` in python3.3."
.endif

#.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
