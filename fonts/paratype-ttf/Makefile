# $NetBSD: Makefile,v 1.6 2022/04/23 23:34:21 tnn Exp $

DISTNAME=	paratype-ttf-20140616
CATEGORIES=	fonts
DISTFILES=	PTSans.zip PTSerif.zip PTMono.zip
SITES.PTSans.zip=	-https://company.paratype.com/system/attachments/629/original/ptsans.zip
SITES.PTSerif.zip=	-https://company.paratype.com/system/attachments/634/original/ptserif.zip
SITES.PTMono.zip=	-https://company.paratype.com/system/attachments/631/original/ptmono.zip
DIST_SUBDIR=	${DISTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://company.paratype.com/pt-sans-pt-serif
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
