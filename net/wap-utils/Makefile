# $NetBSD: Makefile,v 1.9 2003/12/28 00:33:23 wiz Exp $
#

DISTNAME=	ap-utils-1.3.2
PKGNAME=	w${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ap-utils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wojtek@tensor.3miasto.net
HOMEPAGE=	http://ap-utils.polesye.net/
COMMENT=	Wireless access points UNIX management tool

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
