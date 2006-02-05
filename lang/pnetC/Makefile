# $NetBSD: Makefile,v 1.10 2006/02/05 23:09:47 joerg Exp $
#

DISTNAME=	pnetC-0.6.6
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	C language binding for DotGNU Portable .NET

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../lang/pnet/buildlink3.mk"
.include "../../lang/pnetlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
