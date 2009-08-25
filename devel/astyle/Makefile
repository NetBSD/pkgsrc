# $NetBSD: Makefile,v 1.13 2009/08/25 11:56:34 wiz Exp $
#

DISTNAME=	astyle_1.13.6.1
PKGNAME=	astyle-1.13.6.1
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astyle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://astyle.sourceforge.net/
COMMENT=	Reindenter and reformatter of C++, C and Java source code

PKG_DESTDIR_SUPPORT=	user-destdir

HTMLDIR=	${PREFIX}/share/doc/html/astyle
INSTALLATION_DIRS=	bin ${HTMLDIR}

USE_LANGUAGES=	c++

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
CFLAGS+=	-DASTYLE_GCC2
.endif

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} astyle.html \
		astyle_release_notes.html license.html ${DESTDIR}${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
