# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:03 tv Exp $
#

DISTNAME=	mpeg_encode-1.5b-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	multimedia net
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/encode/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://bmrc.berkeley.edu/frame/research/mpeg/mpeg_encode.html
COMMENT=	The Parallel Berkeley MPEG Encoder

WRKSRC=			${WRKDIR}/mpeg_encode
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

post-build:
	@cd ${WRKSRC}/convert && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mpeg_encode ${LOCALBASE}/bin
.for i in eyuvtojpeg jmovie2jpeg mpeg_demux
	${INSTALL_PROGRAM} ${WRKSRC}/convert/${i} ${LOCALBASE}/bin
.endfor
	${INSTALL_DATA_DIR}  ${LOCALBASE}/share/doc/mpeg_encode
.for i in EXTENSIONS INPUT.FORMAT mpeg_encode.1 parallel.param param-summary \
		template.param users-guide.fm users-guide.mif users-guide.ps
	${INSTALL_DATA}  ${WRKSRC}/docs/${i} ${LOCALBASE}/share/doc/mpeg_encode
.endfor
	${INSTALL_DATA_DIR}  ${LOCALBASE}/share/examples/mpeg_encode
	cd ${WRKSRC}/examples ; for i in * ; do \
		${INSTALL_DATA} $$i ${LOCALBASE}/share/examples/mpeg_encode; \
	done
	${INSTALL_MAN} ${WRKSRC}/docs/mpeg_encode.1 ${LOCALBASE}/man/man1

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
