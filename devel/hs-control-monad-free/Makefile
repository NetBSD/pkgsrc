# $NetBSD: Makefile,v 1.2 2021/04/24 04:35:16 pho Exp $

DISTNAME=	control-monad-free-0.6.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Free monads and monad transformers
LICENSE=	public-domain

post-patch:
	${CP} ${FILESDIR}/Setup.hs ${WRKSRC}

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
