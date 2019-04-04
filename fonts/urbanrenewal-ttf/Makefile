# $NetBSD: Makefile,v 1.5 2019/04/04 10:30:03 maya Exp $
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

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

# FreeBSD's unzip doesn't handle the archive:
.if ${OPSYS} == "FreeBSD"
TOOLS_PLATFORM.unzip=	# empty
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
