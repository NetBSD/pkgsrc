# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:58 jschauma Exp $
#

DISTNAME=	astyle_1.13.6.1
PKGNAME=	astyle-1.13.6.1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=astyle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://astyle.sourceforge.net/
COMMENT=	reindenter and reformatter of C++, C and Java source code

HTMLDIR=	${PREFIX}/share/doc/html/astyle

post-extract:
	${MV} -f ${WRKSRC}/makefile ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} astyle.html astyle_release_notes.html\
								 license.html ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
