# $NetBSD: Makefile,v 1.12 2005/10/01 20:45:05 kristerw Exp $
#

DISTNAME=	ttt-1.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install install-man

.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
