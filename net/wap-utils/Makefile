# $NetBSD: Makefile,v 1.23 2014/02/22 17:40:38 wiedi Exp $
#

DISTNAME=	ap-utils-1.3.2
PKGNAME=	w${DISTNAME}
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ap-utils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wojtek@tensor.3miasto.net
HOMEPAGE=	http://ap-utils.polesye.net/
COMMENT=	Wireless access points UNIX management tool

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*-*

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
