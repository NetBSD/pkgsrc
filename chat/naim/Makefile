# $NetBSD: Makefile,v 1.51 2012/06/03 17:24:08 abs Exp $

DISTNAME=	naim-0.11.8.3.2
CATEGORIES=	chat
MASTER_SITES=	http://naim.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://naim.n.ml.org/
COMMENT=	Ncurses-based AIM, ICQ, IRC, and Lily client

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
