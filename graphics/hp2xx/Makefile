# $NetBSD: Makefile,v 1.48 2023/10/21 17:10:32 gdt Exp $
#

DISTNAME=	hp2xx-3.4.4
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU:=hp2xx/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/hp2xx/hp2xx.html
COMMENT=	HPGL converter and previewer

BUILD_DIRS=	sources
USE_TOOLS+=	makeinfo
MAKE_FLAGS=	prefix=${PREFIX}					\
		mandir=${PREFIX}/${PKGMANDIR}				\
		infodir=${PREFIX}/${PKGINFODIR}
MAKE_ENV+=	XLDFLAGS=${LDFLAGS:Q} XCPPFLAGS=${CPPFLAGS:Q}
INFO_FILES=	yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}			\
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}		\
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}

INSTALLATION_DIRS=	bin ${PKGINFODIR} ${PKGMANDIR}/man1

post-extract:
	${CP} ${WRKSRC}/makes/generic.mak ${WRKSRC}/sources/Makefile

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
