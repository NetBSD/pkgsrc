# $NetBSD: Makefile,v 1.9 2005/03/30 19:51:35 wiz Exp $

DISTNAME=	rsynth-2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/ \
		ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/dictionaries/cmudict/
DISTFILES=	rsynth-2.0.tar.gz ${DICT_FILES}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/FAQ-complete
COMMENT=	Public Domain Speech Synthesis System

DICT_FILES+=	README cmudict.0.4.Z cmulex.0.4.Z phoneset.0.4
EXTRACT_ONLY=	rsynth-2.0.tar.gz

DIST_SUBDIR=	rsynth
GNU_CONFIGURE=	YES
USE_X11=	YES

CONFIGURE_ARGS+=--with-aDict="${WRKDIR}/cmudict.0.4"
CONFIGURE_ARGS+=--without-bDict
CONFIGURE_ENV+=	ac_cv_lib_audio=yes XLIBS=-lXt

pre-configure:
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/cmudict.0.4.Z > ${WRKDIR}/cmudict.0.4

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/rsynth/
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${DICT_FILES} ${PREFIX}/share/rsynth/

.include "../../audio/nas/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
