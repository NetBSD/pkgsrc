# $NetBSD: Makefile,v 1.3 2014/03/31 08:31:19 wiz Exp $

DISTNAME=	wildmidi-0.3.5
PKGNAME=	${DISTNAME:S/wildmidi/libwildmidi/}
CATEGORIES=	audio
MASTER_SITES=	https://github.com/Mindwerks/wildmidi/archive/

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://www.mindwerks.net/projects/wildmidi/
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/wildmidi-${DISTNAME}
USE_TOOLS+=	gmake
USE_CMAKE=	yes

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	src/CMakeLists.txt
SUBST_STAGE.man=	post-extract
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
