# $NetBSD: Makefile,v 1.16 2003/06/08 21:25:42 wiz Exp $
#

DISTNAME=	naim-0.11.5.9
CATEGORIES=	chat
MASTER_SITES=	http://shell.n.ml.org/n/naim/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://site.rpi-acm.org/info/naim/
COMMENT=	ncurses-based AIM/IRC client

GNU_CONFIGURE=	YES

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_NCURSES=		# keyname (perhaps also wattr_get, wattr_set)

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
