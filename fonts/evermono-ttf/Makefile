# $NetBSD: Makefile,v 1.5 2019/04/06 08:46:04 wiz Exp $

DISTNAME=	evermono
VERSION=	7.0.0
PKGNAME=	evermono-ttf-${VERSION}
CATEGORIES=	fonts
#MASTER_SITES=	http://www.evertype.com/emono/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.evertype.com/emono/
COMMENT=	Simple, elegant, monowidth font with wide Unicode coverage
LICENSE=	evermono-license

DIST_SUBDIR=	evermono-ttf-${VERSION}

WRKSRC=		${WRKDIR}/evermono-${VERSION}
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${FONTDIR} share/doc/evermono-ttf

post-install:
	${INSTALL_DATA} ${WRKSRC}/emono-licence.txt ${DESTDIR}${PREFIX}/share/doc/evermono-ttf/

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
