# $NetBSD: Makefile,v 1.3 2003/07/17 21:27:09 grant Exp $
#

DISTNAME=	bib2xml-10062002
PKGNAME=	${DISTNAME:C/-(....)(....)/-\2\1/}
WRKSRC=		${WRKDIR}/bib2xml
CATEGORIES=	converters textproc
MASTER_SITES=	http://www.cs.colorado.edu/~henkel/stuff/bib2xml/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.colorado.edu/~henkel/stuff/bib2xml/
COMMENT=	BibTeX to XML converter

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
BUILD_DIRS=	${WRKSRC}/progs

do-install:
	${INSTALL_PROGRAM} ${BUILD_DIRS}/bib2xml ${PREFIX}/bin

.include "../../textproc/btparse/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
