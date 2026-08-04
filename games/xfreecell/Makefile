# $NetBSD: Makefile,v 1.23 2026/08/04 20:28:58 wiz Exp $

DISTNAME=	xfreecell-1.0.5b
PKGREVISION=	3
CATEGORIES=	games
#MASTER_SITES=	#http://www2.giganet.net/~nakayama/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www2.giganet.net/~nakayama/
COMMENT=	Popular freecell card game for X

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

WRKSRC=		${WRKDIR}/xfreecell
NO_CONFIGURE=	YES

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
