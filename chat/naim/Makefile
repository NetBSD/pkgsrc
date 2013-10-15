# $NetBSD: Makefile,v 1.53 2013/10/15 21:20:29 roy Exp $

DISTNAME=	naim-0.11.8.3.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://naim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://naim.n.ml.org/
COMMENT=	curses-based AIM, ICQ, IRC, and Lily client

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
