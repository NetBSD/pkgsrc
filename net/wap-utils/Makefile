# $NetBSD: Makefile,v 1.27 2016/12/18 23:33:11 joerg Exp $
#

DISTNAME=	ap-utils-1.3.2
PKGNAME=	w${DISTNAME}
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ap-utils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wojtek@tensor.3miasto.net
HOMEPAGE=	http://ap-utils.polesye.net/
COMMENT=	Wireless access points UNIX management tool

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
