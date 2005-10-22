# $NetBSD: Makefile,v 1.5 2005/10/22 15:51:02 rillig Exp $
#

DISTNAME=	libjit-0.0.4
CATEGORIES=	devel
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_MAKEINFO=		yes
INFO_FILES=		libjit.info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
