# $NetBSD: Makefile,v 1.3 2019/11/02 22:24:37 rillig Exp $

DISTNAME=	cnr_BETA
PKGNAME=	Code-New-Roman-2.1beta1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=codenewroman/}
EXTRACT_SUFX=	.otf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/codenewroman/
COMMENT=	Programming font
LICENSE=	ofl-v1.1

DIST_SUBDIR=		${PKGNAME_NOREV}
USE_LANGUAGES=		# none
WRKSRC=			${WRKDIR}
NO_BUILD=		yes
FONTS_DIR=		${PREFIX}/share/fonts/X11/OTF
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
