# $NetBSD: Makefile,v 1.2 2000/06/01 11:23:31 rh Exp $

DISTNAME=	opendis-0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://ods.sourceforge.net/dl/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://ods.sourceforge.net/

#USE_PKGLIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
