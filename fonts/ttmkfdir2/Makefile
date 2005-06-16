# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:52 jlam Exp $
#

DISTNAME=	ttmkfdir2.20021109
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	http://people.redhat.com/yshao/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://people.redhat.com/yshao/
COMMENT=	Tool that creates a fonts.scale file

CONFLICTS=	ttmkfdir-[0-9]*

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex
USE_LANGUAGES=	c c++

MAKE_ENV+=	FREETYPE_CONFIG=${FREETYPE_CONFIG}
LDFLAGS+=	${BUILDLINK_LDADD.getopt}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${PREFIX}/bin

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
