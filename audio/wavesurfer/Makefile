# $NetBSD: Makefile,v 1.8 2004/11/27 10:52:06 gson Exp $

DISTNAME=	wavesurfer-1.7.4
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.kth.se/wavesurfer/

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.speech.kth.se/wavesurfer/
COMMENT=	Tool for sound visualization and manipulation

DEPENDS+=	tcl-snack-[0-9]*:../../audio/tcl-snack
DEPENDS+=	tk-[0-9]*:../../x11/tk

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty

SUBST_CLASSES+=		wish
SUBST_MESSAGE.wish=	"Fixing hardcoded command names."
SUBST_STAGE.wish=	post-patch
SUBST_FILES.wish=	wavesurfer.tcl
SUBST_SED.wish=		-e 's,wish8.4,wish,g' \

INSTALLATION_DIRS=	bin lib

do-install:
	${CP} ${WRKSRC}/wavesurfer.tcl ${PREFIX}/bin/wavesurfer
	${CP} -R ${WRKSRC}/wsurf1.7 ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
