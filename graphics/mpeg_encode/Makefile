# $NetBSD: Makefile,v 1.3 2001/11/29 01:12:36 hubertf Exp $
#

DISTNAME=	mpeg_encode-1.5b-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	graphics net
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/encode/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://bmrc.berkeley.edu/frame/research/mpeg/mpeg_encode.html
COMMENT=	The Parallel Berkeley MPEG Encoder

DEPENDS+=	jpeg-6*:../../graphics/jpeg

WRKSRC=		${WRKDIR}/mpeg_encode

post-build:
	${MAKE} do-build WRKSRC=${WRKSRC}/convert

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

.include "../../mk/bsd.pkg.mk"
