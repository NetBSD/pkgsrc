# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:12 jlam Exp $
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
