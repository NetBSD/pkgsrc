# $NetBSD: Makefile,v 1.10 2019/11/02 16:16:21 rillig Exp $

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

#PKG_FAIL_REASON+=		"${DISTNAME} is obsoleted by the builtin \`decimal\` in python3.3."
PYTHON_VERSIONS_ACCEPTED=	27

#.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
