# $NetBSD: Makefile,v 1.21 2020/03/20 11:57:50 nia Exp $

DISTNAME=	mpgtx-1.3.1
PKGREVISION=	1
CATEGORIES=	audio graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpgtx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpgtx.sourceforge.net/
COMMENT=	Split and join MPEG files in various ways

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}	\
			--manprefix=${PREFIX}
USE_LANGUAGES=		c c++

BUILD_TARGET=	mpgtx
PLINKS=		mpgjoin mpgcat mpgsplit mpginfo mpgdemux tagmp3
MLINKS=		mpgcat.1 mpgjoin.1 mpginfo.1 mpgsplit.1 mpgdemux.1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpgtx ${DESTDIR}${PREFIX}/bin
.for f in ${PLINKS}
	${LN} -f ${DESTDIR}${PREFIX}/bin/mpgtx \
		${DESTDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/mpgtx.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for f in ${MLINKS}
	${LN} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/mpgtx.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f}
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/tagmp3.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
