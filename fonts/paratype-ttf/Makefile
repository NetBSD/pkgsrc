# $NetBSD: Makefile,v 1.5 2020/11/06 18:04:26 maya Exp $

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

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/doc/paratype-ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/paratype-ttf

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
