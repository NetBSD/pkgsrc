# $NetBSD: Makefile,v 1.54 2015/08/18 07:31:03 wiz Exp $

DISTNAME=	naim-0.11.8.3.2
PKGREVISION=	2
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
