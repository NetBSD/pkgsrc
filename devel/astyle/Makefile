# $NetBSD: Makefile,v 1.15 2013/05/25 16:39:39 shattered Exp $
#

DISTNAME=	astyle_1.15.3
PKGNAME=	astyle-1.15.3
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astyle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://astyle.sourceforge.net/
COMMENT=	Reindenter and reformatter of C, C++, C# and Java source code
LICENSE=	gnu-gpl-v2

HTMLDIR=	${PREFIX}/share/doc/html/astyle
INSTALLATION_DIRS=	bin ${HTMLDIR}

USE_LANGUAGES=	c++
WRKSRC=		${WRKDIR}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
CFLAGS+=	-DASTYLE_GCC2
.endif

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} astyle.html \
		astyle_release_notes.html license.html ${DESTDIR}${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
