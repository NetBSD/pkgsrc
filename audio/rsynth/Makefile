# $NetBSD: Makefile,v 1.20 2012/10/02 23:48:08 asau Exp $

DISTNAME=	rsynth-2.0
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/synthesis/
DISTFILES=	rsynth-2.0.tar.gz ${DICT_FILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	ftp://svr-ftp.eng.cam.ac.uk/pub/comp.speech/FAQ-complete
COMMENT=	Public Domain Speech Synthesis System

DICT_FILES+=	README cmudict.0.4.Z cmulex.0.4.Z phoneset.0.4
EXTRACT_ONLY=	rsynth-2.0.tar.gz

DIST_SUBDIR=	rsynth
GNU_CONFIGURE=	YES
CONFIGURE_HAS_MANDIR=	NO

USE_TOOLS+=	gzcat

CONFIGURE_ARGS+=--with-aDict="${WRKDIR}/cmudict.0.4"
CONFIGURE_ARGS+=--without-bDict
CONFIGURE_ENV+=	ac_cv_lib_audio=yes XLIBS=-lXt

INSTALLATION_DIRS+= bin share/rsynth

pre-configure:
	${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/cmudict.0.4.Z > ${WRKDIR}/cmudict.0.4

post-install:
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		${INSTALL_DATA} ${DICT_FILES} ${DESTDIR}${PREFIX}/share/rsynth/

.include "../../audio/nas/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
