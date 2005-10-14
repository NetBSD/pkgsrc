# $NetBSD: Makefile,v 1.15 2005/10/14 19:54:39 tonio Exp $
#

DISTNAME=	Maude-2.1.1
PKGNAME=	${DISTNAME:S/M/m/}
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming

USE_TOOLS+= flex bison

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/maude

post-install:
.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
