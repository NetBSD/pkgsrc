# $NetBSD: Makefile,v 1.7 2004/01/13 23:35:38 xtraeme Exp $
#

DISTNAME=	ttt-1.8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

USE_X11=	yes
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install install-man

.include "../../net/libpcap/buildlink2.mk"
.include "../../x11/blt/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
