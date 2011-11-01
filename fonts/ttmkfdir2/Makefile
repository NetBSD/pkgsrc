# $NetBSD: Makefile,v 1.18 2011/11/01 06:01:13 sbd Exp $
#

DISTNAME=	ttmkfdir2.20021109
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	4
CATEGORIES=	fonts x11
MASTER_SITES=	http://people.redhat.com/yshao/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.redhat.com/yshao/
COMMENT=	Tool that creates a fonts.scale file

CONFLICTS=	ttmkfdir-[0-9]*

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex
USE_LANGUAGES=	c c++

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	FREETYPE_CONFIG=${FREETYPE_CONFIG:Q}
LDFLAGS+=	${BUILDLINK_LDADD.getopt}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttmkfdir ${DESTDIR}${PREFIX}/bin

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
