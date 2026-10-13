# $NetBSD: Makefile,v 1.1 2026/10/13 08:36:47 drixter Exp $

DISTNAME=	pamtester-0.1.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pamtester/}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://pamtester.sourceforge.net/
COMMENT=	Program to test the PAM facility
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
.include "../../mk/pam.buildlink3.mk"
