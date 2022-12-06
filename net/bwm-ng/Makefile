# $NetBSD: Makefile,v 1.4 2022/12/06 14:41:38 vins Exp $

DISTNAME=	bwm-ng-0.6.3
CATEGORIES=	net
MASTER_SITES=	https://www.gropp.org/bwm-ng/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.gropp.org/bwm-ng/
COMMENT=	Console-based bandwidth monitor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		autoconf automake autoreconf
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
FAKE_NCURSES=		yes

pre-configure:
	${RUN} set -e; cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
