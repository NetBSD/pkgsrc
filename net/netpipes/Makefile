# $NetBSD: Makefile,v 1.9 2012/10/23 17:18:41 asau Exp $

DISTNAME=	netpipes-4.2-export
PKGNAME=	${DISTNAME:S/-export//}
CATEGORIES=	net
MASTER_SITES=	http://web.purplefrog.com/ftp/thoth/netpipes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.purplefrog.com/~thoth/netpipes/netpipes.html
COMMENT=	Utilities for communicating via sockets

WRKSRC=		${WRKDIR}
USE_TOOLS+=	tbl

LIBS.SunOS+=	-lsocket -lnsl
MAKE_ENV+=	LIBS=${LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}

post-build:
.for f in faucet.1 hose.1
	cd ${WRKSRC} && ${TBL} ${f} > ${f}.new && ${MV} -f ${f}.new ${f}
.endfor

.include "../../mk/bsd.pkg.mk"
