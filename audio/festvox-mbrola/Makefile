# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 19:35:44 proff Exp $

DISTNAME=	festvox-mbrola-1.3.1
WRKSRC=		${WRKDIR}/festival
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.3.1/
DISTFILES=	festvox_en1.tar.gz

MAINTAINER=	proff@iq.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival.html

DEPENDS+=	festival-1.3.1:../festival \
		festlex-poslex-1.3.1:../festlex-poslex \
		festlex-oald-1.3.1:../festlex-oald \
		mbrola-linux-301g1:../mbrola-linux \
		mbrolavox-en1-980910:../mbrolavox-en1

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival
MBROLA=		${FHOME}/lib/voices/english/rab_mbrola

post-extract:
	@ chmod -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 chmod 755

do-install:
	${INSTALL_DATA_DIR} ${FHOME}/rab_mbrola
	cd ${WRKSRC} && pax -r -w * ${FHOME}
#ugh
	ln -fs ../../../../../mbrola/voices/en1/en1 ${MBROLA}
	ln -fs ../../../../../mbrola/voices/en1/en1mrpa ${MBROLA}

.include "../../mk/bsd.pkg.mk"
