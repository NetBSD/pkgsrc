# $NetBSD: Makefile,v 1.52 2012/10/03 00:02:41 asau Exp $

DISTNAME=	naim-0.11.8.3.2
CATEGORIES=	chat
MASTER_SITES=	http://naim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://naim.n.ml.org/
COMMENT=	Ncurses-based AIM, ICQ, IRC, and Lily client

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
