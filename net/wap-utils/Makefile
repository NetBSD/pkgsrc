# $NetBSD: Makefile,v 1.7 2003/09/27 17:07:38 grant Exp $
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
USE_NCURSES=		# redrawwin()

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
