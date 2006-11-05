# $NetBSD: Makefile,v 1.1.1.1 2006/11/05 01:43:59 minskim Exp $

DISTNAME=	libhangul-0.0.3
CATEGORIES=	inputmethod korean
MASTER_SITES=	http://kldp.net/frs/download.php/3641/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://kldp.net/projects/hangul/
COMMENT=	Library used by Korean input methods

#USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libhangul.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
