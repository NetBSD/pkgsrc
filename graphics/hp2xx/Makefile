# $NetBSD: Makefile,v 1.43 2013/01/26 21:37:51 adam Exp $
#

DISTNAME=	hp2xx-3.4.4
PKGREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/hp2xx/hp2xx.html
COMMENT=	HPGL converter and previewer

BUILD_DIRS=	sources
USE_TOOLS+=	makeinfo
MAKE_FLAGS=	prefix=${PREFIX}					\
		mandir=${PREFIX}/${PKGMANDIR}				\
		infodir=${PREFIX}/${PKGINFODIR}
MAKE_ENV+=	XLDFLAGS=${LDFLAGS:Q} XCPPFLAGS=${CPPFLAGS:Q}
INFO_FILES=	# PLIST

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}			\
		mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}			\
		infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1

post-extract:
	${CP} ${WRKSRC}/makes/generic.mak ${WRKSRC}/sources/Makefile

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
