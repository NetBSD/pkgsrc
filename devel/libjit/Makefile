# $NetBSD: Makefile,v 1.8 2006/03/05 16:27:24 jlam Exp $
#

DISTNAME=	libjit-0.0.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
INFO_FILES=		libjit.info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
