# $NetBSD: Makefile,v 1.13 2019/07/08 10:36:25 nia Exp $

DISTNAME=	Inconsolata.otf
PKGNAME=	inconsolata-ttf-20090207
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://www.levien.com/type/myfonts/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.levien.com/type/myfonts/inconsolata.html
COMMENT=	Inconsolata TrueType font
LICENSE=	ofl-v1.1

CONFLICTS=	inconsolata-[0-9]*

DIST_SUBDIR=	${PKGNAME_NOREV}

EXTRACT_ONLY=	# empty

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
