# $NetBSD: Makefile,v 1.9 2004/04/25 03:59:47 snj Exp $

DISTNAME=	cook-2.22
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/cook/

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://www.canb.auug.org.au/~millerp/cook/cook.html
COMMENT=	More powerful replacement for the traditional make(1) tool

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	# defined

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
