# $NetBSD: Makefile,v 1.11 2010/07/06 10:17:13 jmmv Exp $
#

DISTNAME=	pnetC-0.6.6
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	C language binding for DotGNU Portable .NET

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../lang/pnet/buildlink3.mk"
.include "../../lang/pnetlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
