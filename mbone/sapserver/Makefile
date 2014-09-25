# $NetBSD: Makefile,v 1.9 2014/09/25 14:32:35 jperkin Exp $
#

DISTNAME=	miniSAPserver-0.2.4
CATEGORIES=	mbone
MASTER_SITES=	http://download.videolan.org/pub/videolan/miniSAPserver/0.2.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/
COMMENT=	Mini SAP server from the VideoLan project

GNU_CONFIGURE=	YES

USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/sapserver

.include "../../mk/bsd.pkg.mk"
