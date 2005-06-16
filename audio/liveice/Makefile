# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:39 jlam Exp $
#

DISTNAME=	liveice
PKGNAME=	liveice-0.20001121
CATEGORIES=	audio
MASTER_SITES=	http://star.arm.ac.uk/~spm/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://star.arm.ac.uk/~spm/software/liveice.html
COMMENT=	Source client for Icecast

DEPENDS+=	mpg123-0.5*:../../audio/mpg123
DEPENDS+=	lame-3.*:../../audio/lame
DEPENDS+=	tk>=8.0:../../x11/tk

GNU_CONFIGURE=	YES
DIST_SUBDIR=	liveice-0.20001121
LIBS+=		${LIBOSSAUDIO}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/liveice ${PREFIX}/bin
	( ${ECHO} '#!${LOCALBASE}/bin/wish' ; \
	  ${TAIL} +2 ${WRKSRC}/liveiceconfigure.tk \
	) >${PREFIX}/bin/liveiceconfigure.tk
	${CHGRP} ${BINGRP}	${PREFIX}/bin/liveiceconfigure.tk
	${CHOWN} ${BINOWN}	${PREFIX}/bin/liveiceconfigure.tk
	${CHMOD} ${BINMODE}	${PREFIX}/bin/liveiceconfigure.tk
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/liveice
	for i in README.frontend README.liveice README.quickstart \
		README.xingmp3enc README_new_mixer.txt ; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/liveice ; \
	done

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
