# $NetBSD: Makefile,v 1.3 2006/08/23 11:18:50 joerg Exp $
#

DISTNAME=		pyproj-1.7.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyproj/proj/}
CATEGORIES=		geography
MASTER_SITES=		http://www.cdc.noaa.gov/people/jeffrey.s.whitaker/python/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.cdc.noaa.gov/people/jeffrey.s.whitaker/python/
COMMENT=		python wrapper for proj

PYDISTUTILSPKG=			true
PYTHON_VERSIONS_ACCEPTED=	23 24

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
	${INSTALL} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGNAME}

.include "../../lang/python/extension.mk"

.include "../../misc/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
