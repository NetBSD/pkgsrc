# $NetBSD: Makefile,v 1.6 2020/01/26 17:31:12 rillig Exp $
#

DISTNAME=	urbanrenewal
VERSION=	201102
PKGNAME=	${DISTNAME}-ttf-${VERSION}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.kreativekorp.com/swdownload/fonts/urban/
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	https://www.kreativekorp.com/software/fonts/urbanrenewal.shtml
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
