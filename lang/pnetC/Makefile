# $NetBSD: Makefile,v 1.7 2004/10/03 00:15:02 tv Exp $
#

DISTNAME=	pnetC-0.6.6
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	C language binding for DotGNU Portable .NET

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../lang/pnet/buildlink3.mk"
.include "../../lang/pnetlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
