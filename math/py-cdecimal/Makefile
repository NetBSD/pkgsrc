# $NetBSD: Makefile,v 1.2 2014/01/25 09:05:56 wiz Exp $

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

#PKG_FAIL_REASON+=	"${DISTNAME} is obsoleted by the builtin \`decimal\` in python3.3."
PYTHON_VERSIONS_INCOMPATIBLE=	33

#.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
