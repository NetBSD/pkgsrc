# $NetBSD: Makefile,v 1.1 2022/09/26 16:07:06 ryoon Exp $

PKGNAME=	noto-cjk-fonts-20220816
CATEGORIES=	fonts
TAG=		468a39cc0f9b90ad0c5922194657f32597917a8b
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlefonts/noto-cjk/raw/${TAG}/Sans/Variable/OTC/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/googlefonts/noto-cjk/
COMMENT=	Google Noto CJK fonts
LICENSE=	ofl-v1.1

SITES.NotoSerifCJK-VF.otf.ttc=	${MASTER_SITE_GITHUB:=googlefonts/noto-cjk/raw/${TAG}/Serif/Variable/OTC/}
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	NotoSansCJK-VF.otf.ttc \
		NotoSansMonoCJK-VF.otf.ttc \
		NotoSerifCJK-VF.otf.ttc

CONFLICTS+=	noto-ttf-[0-9]*

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-extract:
.for file in ${DISTFILES}
	${CP} ${_DISTDIR}/${file} ${WRKSRC}/${file}
.endfor

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
