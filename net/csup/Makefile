# $NetBSD: Makefile,v 1.3 2007/12/02 08:32:24 rillig Exp $
#

DISTNAME=	csup-snap-20070216
PKGNAME=	${DISTNAME:S/-snap//}
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://www.mu.org/~mux/csup.html
COMMENT=	Rewrite of the CVSup file updating client in C

USE_TOOLS+=	lex yacc
WRKSRC=		${WRKDIR}/csup

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CFLAGS+=    ${PTHREAD_CFLAGS}
LDFLAGS+=   ${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}

BUILDLINK_TRANSFORM+=	rm:-Werror

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csup ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/csup.1 ${PREFIX}/${PKGMANDIR}/man1/csup.1

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
