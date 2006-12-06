# $NetBSD: Makefile,v 1.17 2006/12/06 14:14:11 joerg Exp $

DISTNAME=	cook-2.26
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/cook/

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://www.canb.auug.org.au/~millerp/cook/cook.html
COMMENT=	More powerful replacement for the traditional make(1) tool

USE_TOOLS+=	msgfmt yacc perl:run
GNU_CONFIGURE=	yes

REPLACE_PERL=	bin/cook_rsh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
