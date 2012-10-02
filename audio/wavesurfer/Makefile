# $NetBSD: Makefile,v 1.18 2012/10/02 23:48:12 asau Exp $

DISTNAME=	wavesurfer-1.8.5
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/wavesurfer/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/wavesurfer/
COMMENT=	Tool for sound visualization and manipulation

DEPENDS+=	tcl-snack-[0-9]*:../../audio/tcl-snack
DEPENDS+=	tk-[0-9]*:../../x11/tk

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	Fixing hardcoded command names.
SUBST_STAGE.wish=	post-patch
SUBST_FILES.wish=	wavesurfer.tcl
SUBST_SED.wish=		-e 's,wish8.4,wish,g'

INSTALLATION_DIRS=	bin lib

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wavesurfer.tcl \
		${DESTDIR}${PREFIX}/bin/wavesurfer
	cd ${WRKSRC} && pax -wr -pm wsurf1.8 ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
