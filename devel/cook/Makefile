# $NetBSD: Makefile,v 1.2 2001/08/01 15:25:24 wiz Exp $

DISTNAME=	cook-2.17
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/cook/

MAINTAINER=	groo@netbsd.org
HOMEPAGE=	http://www.canb.auug.org.au/~millerp/cook/cook.html
COMMENT=	More powerful replacement for the traditional make(1) tool

DEPENDS+=	rx-*:../../devel/rx
BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=	# defined

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
