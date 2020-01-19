# $NetBSD: Makefile,v 1.1 2020/01/19 23:45:50 pho Exp $

DISTNAME=	regex-tdfa-1.3.1.0
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Pure Haskell Tagged DFA Backend for "Text.Regex" (regex-base)
LICENSE=	modified-bsd

post-patch:
	${RUN}${CP} -f ${FILESDIR}/Setup.hs ${WRKSRC}/

.include "../../mk/haskell.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
