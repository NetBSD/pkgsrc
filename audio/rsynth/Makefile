# New ports collection makefile for:	rsynth
# Version required:	2.0
# Date created:		03 Jan 1995
# Whom:			faulkner@mpd.tandem.com
#
# $NetBSD: Makefile,v 1.4 2001/12/22 04:11:39 fredb Exp $
# FreeBSD Id: Makefile,v 1.8 1996/11/15 23:14:14 obrien Exp
#

DISTNAME=	rsynth-2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/ \
		ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/dictionaries/cmudict/
DISTFILES=	rsynth-2.0.tar.gz ${DICT_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/FAQ-complete
COMMENT=	Public Domain Speech Synthesis System

DEPENDS+=	gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=	nas>=1.4:../../audio/nas

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

.include "../../mk/bsd.pkg.mk"
