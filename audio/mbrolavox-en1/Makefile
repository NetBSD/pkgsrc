# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 19:37:09 proff Exp $

DISTNAME=	mbrolavox-en1-980910
WRKSRC=		${WRKDIR}
CATEGORIES=	audio
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/en1/
DISTFILES=	en1-980910.zip

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	mbrola-linux-301g1:../mbrola-linux

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=

NO_BUILD=	yes

MHOME=		${PREFIX}/share/mbrola/voices

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${MHOME}
	cd ${WRKSRC} && pax -r -w en1 ${MHOME}

.include "../../mk/bsd.pkg.mk"
