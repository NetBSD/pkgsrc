# $NetBSD: Makefile,v 1.3 2000/08/14 19:15:54 wiz Exp $

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
