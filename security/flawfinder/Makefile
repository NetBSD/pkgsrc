# $NetBSD: Makefile,v 1.32 2026/10/07 17:15:41 adam Exp $

DISTNAME=	flawfinder-2.0.20
CATEGORIES=	security devel
MASTER_SITES=	https://dwheeler.com/flawfinder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dwheeler.com/flawfinder/
COMMENT=	Python program to find flaws in C/C++ programs
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/flawfinder.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
