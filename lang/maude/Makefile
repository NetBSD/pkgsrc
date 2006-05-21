# $NetBSD: Makefile,v 1.17 2006/05/21 02:21:52 wiz Exp $
#

DISTNAME=	Maude-2.1.1
PKGNAME=	${DISTNAME:S/M/m/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/download/ \
		http://maude.cs.uiuc.edu/download/current/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://maude.cs.uiuc.edu/
COMMENT=	System for equational and rewriting logic specification/programming

USE_LANGUAGES=	c c++
USE_TOOLS+=	flex bison

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/maude

.include "../../devel/buddy/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
