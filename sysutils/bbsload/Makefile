# $NetBSD: Makefile,v 1.3 2003/03/18 01:07:56 jschauma Exp $
#

DISTNAME=	bbsload-0.2.5
CATEGORIES=	sysutils x11 wm
MASTER_SITES=	http://bbtools.thelinuxcommunity.org/sources/

MAINTAINER=	pino@dohd.org
HOMEPAGE=	http://bbtools.thelinuxcommunity.org/
COMMENT=	Small (in dimensions) tool to display the avarage load

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_X11BASE=		YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbsload.1 ${PREFIX}/man/man1/bbsload.1

.include "../../mk/bsd.pkg.mk"
