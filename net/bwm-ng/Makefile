# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:48 rillig Exp $

DISTNAME=	bwm-ng-0.6.1
CATEGORIES=	net
MASTER_SITES=	http://www.gropp.org/bwm-ng/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gropp.org/?id=projects&sub=bwm-ng
COMMENT=	Console-based bandwidth monitor
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
