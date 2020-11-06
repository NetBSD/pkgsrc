# $NetBSD: Makefile,v 1.61 2020/11/06 18:04:27 maya Exp $
#

DISTNAME=	umefont_610
PKGNAME=	${DISTNAME:S/_/-ttf-0./}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=ume-font/63494/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://osdn.jp/projects/ume-font/wiki/FrontPage
COMMENT=	Ume 18 Japanese fonts (Mincho and Gothic)
LICENSE=	mplusfont

WRKSRC=		${WRKDIR}/${DISTNAME:C/([a-z]+)-//}

CONFLICTS=	umefont<=0.421
SUPERSEDES=	umefont<=0.421

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	${PREFIX}/share/doc/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/license.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
