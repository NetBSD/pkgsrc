# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:17 jlam Exp $
#

DISTNAME=	libjit-0.0.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_MAKEINFO=		yes
INFO_FILES=		libjit.info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
