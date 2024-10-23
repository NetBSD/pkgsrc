# $NetBSD: Makefile,v 1.6 2024/10/23 10:00:20 nia Exp $
#

DISTNAME=	chksniff-0.2
CATEGORIES=	net security
#MASTER_SITES=	http://virtus.ath.cx/chksniff/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://virtus.ath.cx/chksniff/
COMMENT=	Small tool to check for promiscuous interfaces

INSTALLATION_DIRS=	bin

GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lsocket

.include "../../mk/bsd.pkg.mk"
