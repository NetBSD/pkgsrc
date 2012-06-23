# $NetBSD: Makefile,v 1.8 2012/06/23 22:43:59 dholland Exp $

DISTNAME=	netpipes-4.2-export
PKGNAME=	${DISTNAME:S/-export//}
CATEGORIES=	net
MASTER_SITES=	http://web.purplefrog.com/ftp/thoth/netpipes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.purplefrog.com/~thoth/netpipes/netpipes.html
COMMENT=	Utilities for communicating via sockets

PKG_DESTDIR_SUPPORT=	user-destdir

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
