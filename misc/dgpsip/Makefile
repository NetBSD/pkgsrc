# $NetBSD: Makefile,v 1.3 2003/09/22 13:43:04 wiz Exp $

DISTNAME=	dgpsip-1.28
CATEGORIES=	misc
MASTER_SITES=	http://www.wsrcc.com/wolfgang/ftp/

MAINTAINER=     wsr+dgpsip@wsrcc.com
HOMEPAGE=	http://www.wsrcc.com/wolfgang/gps/dgps-ip.html
COMMENT=	Differential GPS over IP communication device

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl -lresolv
.endif

.include "../../mk/bsd.pkg.mk"
