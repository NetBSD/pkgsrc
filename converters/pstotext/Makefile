# $NetBSD: Makefile,v 1.6 2026/08/04 20:28:47 wiz Exp $

DISTNAME=	pstotext-1.9
PKGREVISION=	2
CATEGORIES=	converters print
MASTER_SITES=	# ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/contrib/

MAINTAINER=	schaecsn@gmx.net
HOMEPAGE=	http://pages.cs.wisc.edu/~ghost/doc/pstotext.htm
COMMENT=	Postscript to text converter
#LICENSE=	see the end of pstotext.txt.

USE_TOOLS+=	gs:run
USE_TOOLS+=	gmake

SUBST_CLASSES+=	gs
SUBST_STAGE.gs=	do-configure
SUBST_FILES.gs=	main.c
SUBST_SED.gs=	-e 's|@GS_CMD@|${TOOLS_PATH.gs}|'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pstotext.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/pstotext.hlp ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/pstotext.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
