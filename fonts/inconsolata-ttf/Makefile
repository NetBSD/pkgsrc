# $NetBSD: Makefile,v 1.12 2019/04/06 08:50:20 wiz Exp $

DISTNAME=	Inconsolata.otf
PKGNAME=	inconsolata-ttf-20090207
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://www.levien.com/type/myfonts/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.levien.com/type/myfonts/inconsolata.html
COMMENT=	Inconsolata TrueType font
LICENSE=	ofl-v1.1

CONFLICTS=	inconsolata-[0-9]*

DIST_SUBDIR=	${PKGNAME_NOREV}

EXTRACT_ONLY=	# empty

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
