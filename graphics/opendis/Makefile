# $NetBSD: Makefile,v 1.1.1.1 2000/05/12 03:07:40 sommerfeld Exp $

DISTNAME=	opendis-0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://ods.sourceforge.net/dl/

MAINTAINER=	sommerfeld@netbsd.org
HOMEPAGE=	http://ods.sourceforge.net/

#USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
