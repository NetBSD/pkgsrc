# $NetBSD: Makefile,v 1.3 2003/02/23 10:37:53 wiz Exp $
#

DISTNAME=	ap-utils-1.3.1
PKGNAME=	w${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ap-utils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wojtek@tensor.3miasto.net
HOMEPAGE=	http://ap-utils.polesye.net
COMMENT=	Wireless access points UNIX management tool

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_NCURSES=	# redrawwin()

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
