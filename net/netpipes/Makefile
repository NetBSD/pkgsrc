# $NetBSD: Makefile,v 1.2 2005/11/07 00:00:23 jlam Exp $

DISTNAME=	netpipes-4.2-export
PKGNAME=	${DISTNAME:S/-export//}
CATEGORIES=	net
MASTER_SITES=	http://web.purplefrog.com/ftp/thoth/netpipes/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://web.purplefrog.com/~thoth/netpipes/netpipes.html
COMMENT=	utilities for communicating via sockets

WRKSRC=		${WRKDIR}

LIBS.SunOS=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
