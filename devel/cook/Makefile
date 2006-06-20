# $NetBSD: Makefile,v 1.15 2006/06/20 22:09:16 minskim Exp $

DISTNAME=	cook-2.22
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/cook/

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://www.canb.auug.org.au/~millerp/cook/cook.html
COMMENT=	More powerful replacement for the traditional make(1) tool

USE_TOOLS+=	msgfmt yacc
GNU_CONFIGURE=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
