# $NetBSD: Makefile,v 1.5 2016/09/15 20:21:37 wiedi Exp $

DISTNAME=	wildmidi-0.4.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	https://github.com/Mindwerks/wildmidi/archive/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mindwerks.net/projects/wildmidi/
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/wildmidi-${DISTNAME}
USE_LANGUAGES=	c99
USE_TOOLS+=	gmake
USE_CMAKE=	yes

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	src/CMakeLists.txt
SUBST_STAGE.man=	post-extract
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
