# $NetBSD: Makefile,v 1.1 2021/04/23 08:18:25 pho Exp $

DISTNAME=	these-1.1.1.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Either-or-both data type
LICENSE=	modified-bsd

# Setup.hs is missing from the package.
post-patch:
	${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/Setup.hs

.include "../../mk/haskell.mk"
.include "../../devel/hs-assoc/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
