# $NetBSD: Makefile,v 1.1.1.1 2004/05/16 01:12:14 xtraeme Exp $
#

DISTNAME=	libjit-0.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

INFO_FILES=		libjit.info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
