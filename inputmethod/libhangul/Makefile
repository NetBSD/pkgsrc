# $NetBSD: Makefile,v 1.2 2007/05/09 17:29:39 minskim Exp $

DISTNAME=	libhangul-0.0.4
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/3733/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/hangul/
COMMENT=	Library used by Korean input methods

#USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libhangul.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
