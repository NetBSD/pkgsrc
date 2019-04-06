# $NetBSD: Makefile,v 1.4 2019/04/06 08:56:01 wiz Exp $

DISTNAME=	paratype-ttf-20140616
CATEGORIES=	fonts
MASTER_SITES=	http://www.paratype.com/uni/public/
DISTFILES=	PTSans.zip PTSerif.zip PTMono.zip
DIST_SUBDIR=	${DISTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paratype.com/public/
COMMENT=	Public Fonts for Minority Languages of Russia
LICENSE=	paratype

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	share/doc/paratype-ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/paratype-ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
