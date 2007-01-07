# $NetBSD: Makefile,v 1.14 2007/01/07 09:13:56 rillig Exp $
#

DISTNAME=	mpgtx-1.3.1
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpgtx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpgtx.sourceforge.net/
COMMENT=	Split and join MPEG files in various ways

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}	\
			--manprefix=${PREFIX:Q}
USE_LANGUAGES=	c c++

BUILD_TARGET=	mpgtx
PLINKS=		mpgjoin mpgcat mpgsplit mpginfo mpgdemux tagmp3
MLINKS=		mpgcat.1 mpgjoin.1 mpginfo.1 mpgsplit.1 mpgdemux.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpgtx ${PREFIX}/bin
.for f in ${PLINKS}
	${LN} -f ${PREFIX}/bin/mpgtx ${PREFIX}/bin/${f}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/mpgtx.1 ${PREFIX}/${PKGMANDIR}/man1
.for f in ${MLINKS}
	${LN} -f ${PREFIX}/${PKGMANDIR}/man1/mpgtx.1 ${PREFIX}/${PKGMANDIR}/man1/${f}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/tagmp3.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
