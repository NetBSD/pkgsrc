# $NetBSD: Makefile,v 1.8 2004/06/12 02:28:46 grant Exp $
#

DISTNAME=	astyle_1.13.6.1
PKGNAME=	astyle-1.13.6.1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astyle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://astyle.sourceforge.net/
COMMENT=	Reindenter and reformatter of C++, C and Java source code

HTMLDIR=	${PREFIX}/share/doc/html/astyle

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-2*)
CFLAGS+=	-DASTYLE_GCC2
.endif

post-extract:
	${MV} -f ${WRKSRC}/makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} astyle.html \
		astyle_release_notes.html license.html ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
