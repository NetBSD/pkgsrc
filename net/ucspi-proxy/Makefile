# $NetBSD: Makefile,v 1.2 2020/11/19 09:35:40 schmonz Exp $

DISTNAME=	ucspi-proxy-1.1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://untroubled.org/ucspi-proxy/
COMMENT=	Proxy between an UCSPI client and server
LICENSE=	gnu-gpl-v2

DJB_MAKE_TARGETS=	no
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}

.include "../../devel/bglibs/buildlink3.mk"
.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
