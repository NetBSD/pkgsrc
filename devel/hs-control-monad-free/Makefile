# $NetBSD: Makefile,v 1.1 2020/03/30 16:36:06 riastradh Exp $

DISTNAME=	control-monad-free-0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=control-monad-free-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pepeiborra/control-monad-free
COMMENT=	Free monads and monad transformers
LICENSE=	public-domain

USE_LANGUAGES=	# none

post-patch:
	${CP} ${FILESDIR}/Setup.hs ${WRKSRC}

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
