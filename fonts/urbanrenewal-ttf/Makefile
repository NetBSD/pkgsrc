# $NetBSD: Makefile,v 1.3 2014/06/01 16:35:37 wiz Exp $
#

DISTNAME=	urbanrenewal
VERSION=	201102
PKGNAME=	${DISTNAME}-ttf-${VERSION}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.kreativekorp.com/swdownload/fonts/urban/
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.kreativekorp.com/software/fonts/urbanrenewal.shtml
COMMENT=	Insanely great TT versions of the city-named fonts of Mac OS Classic
LICENSE=	kreativekorp-free-license

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

TTFPATH=	share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS=	${TTFPATH}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
