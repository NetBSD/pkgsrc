# $NetBSD: Makefile,v 1.7 2010/02/11 22:17:36 joerg Exp $

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

INSTALLATION_DIRS=	bin ${PKGMANDIR}

post-build:
	cd ${WRKSRC}; for f in faucet.1 hose.1; do			\
		${TBL} $$f > $$f.new; ${MV} -f $$f.new $$f;		\
	done

.include "../../mk/bsd.pkg.mk"
