# $NetBSD: Makefile,v 1.18 2007/10/14 02:04:38 obache Exp $
#

DISTNAME=	ttt-1.8.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install install-man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56]*)
.include "../../mk/pthread.buildlink3.mk"
.endif
.endif

.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
