# $NetBSD: Makefile,v 1.1 2020/11/18 14:17:11 schmonz Exp $

DISTNAME=	ucspi-proxy-1.1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://untroubled.org/ucspi-proxy/
COMMENT=	Proxy between an UCSPI client and server
LICENSE=	gnu-gpl-v2

DJB_MAKE_TARGETS=	no
DJB_RESTRICTED=		no
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
