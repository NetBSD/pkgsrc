# $NetBSD: Makefile,v 1.12 2004/06/02 06:56:07 itojun Exp $
#

DISTNAME=	chicken-1.51
CATEGORIES=	lang
MASTER_SITES=	http://www.call-with-current-continuation.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	test

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=	F77=${FALSE}

.include "../../mk/bsd.pkg.mk"
