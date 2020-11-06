# $NetBSD: Makefile,v 1.15 2020/11/06 18:04:25 maya Exp $

PKGNAME=	inconsolata-ttf-2.001
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/fonts/raw/${TAG}/ofl/inconsolata/}
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES+=	Inconsolata-Bold.ttf
DISTFILES+=	Inconsolata-Regular.ttf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.levien.com/type/myfonts/inconsolata.html
COMMENT=	Inconsolata TrueType font
LICENSE=	ofl-v1.1

TAG=		efcbdc5d93ada0d4f9fa83389aba7cdbc797606f

CONFLICTS=	inconsolata-[0-9]*

EXTRACT_ONLY=	# empty

WRKSRC=		${WRKDIR}

do-extract:
.for file in ${DISTFILES}
	${CP} ${_DISTDIR}/${file} ${WRKSRC}/${file}
.endfor

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
