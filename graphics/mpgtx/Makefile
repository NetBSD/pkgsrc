# $NetBSD: Makefile,v 1.9 2005/06/16 06:57:58 jlam Exp $
#

DISTNAME=	mpgtx-1.3.1
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpgtx/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mpgtx.sourceforge.net/
COMMENT=	Split and join MPEG files in various ways

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}	\
			--manprefix=${PREFIX}
BUILD_TARGET=	mpgtx
PLINKS=		mpgjoin mpgcat mpgsplit mpginfo mpgdemux tagmp3
MLINKS=		mpgcat.1 mpgjoin.1 mpginfo.1 mpgsplit.1 mpgdemux.1

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpgtx ${PREFIX}/bin
.for f in ${PLINKS}
	${LN} -f ${PREFIX}/bin/mpgtx ${PREFIX}/bin/${f}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/mpgtx.1 ${PREFIX}/man/man1
.for f in ${MLINKS}
	${LN} -f ${PREFIX}/man/man1/mpgtx.1 ${PREFIX}/man/man1/${f}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/tagmp3.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
