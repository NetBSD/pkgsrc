# $NetBSD: Makefile,v 1.5 2004/05/21 23:59:30 reed Exp $
#

DISTNAME=	ttmkfdir2.20021109
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	http://people.redhat.com/yshao/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://people.redhat.com/yshao/
COMMENT=	Tool that creates a fonts.scale file

CONFLICTS=	ttmkfdir-[0-9]*

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	lex make
USE_LANGUAGES=	c c++

MAKE_ENV+=	FREETYPE_CONFIG=${FREETYPE_CONFIG}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
