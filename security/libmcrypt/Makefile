# $NetBSD: Makefile,v 1.4 2001/06/20 21:35:05 jlam Exp $

DISTNAME=	libmcrypt-2.4.7
CATEGORIES=	security devel
MASTER_SITES=	http://mcrypt.hellug.gr/lib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mcrypt.hellug.gr/
COMMENT=	crypto algorithms library

USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
#USE_LTDL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/libtool/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
