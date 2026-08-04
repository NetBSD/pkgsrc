# $NetBSD: Makefile,v 1.29 2026/08/04 20:28:57 wiz Exp $
#

DISTNAME=	tuxmath-2001.09.07-0102
PKGNAME=	tuxmath-20010907
PKGREVISION=	17
CATEGORIES=	games math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxmath/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/tuxmath/
COMMENT=	Educational math arcade game

WRKSRC=		${WRKDIR}/tuxmath
USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin share/doc/tuxmath

pre-install:
	${FIND} ${WRKSRC} -name CVS -type d  -print | ${XARGS} ${RM} -rf
	${RM} -rf ${WRKSRC}/data/images/.xvpics
	${RM} -rf ${WRKSRC}/data/images/status/.xvpics

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/README.txt ${DESTDIR}${PREFIX}/share/doc/tuxmath/

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
