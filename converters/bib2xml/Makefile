# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	bib2xml-10062002
PKGNAME=	${DISTNAME:C/-(....)(....)/-\2\1/}
CATEGORIES=	converters textproc
MASTER_SITES=	http://www.cs.colorado.edu/~henkel/stuff/bib2xml/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.colorado.edu/~henkel/stuff/bib2xml/
COMMENT=	BibTeX to XML converter

WRKSRC=		${WRKDIR}/bib2xml
GNU_CONFIGURE=	YES
BUILD_DIRS=	${WRKSRC}/progs

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${BUILD_DIRS}/bib2xml ${PREFIX}/bin

.include "../../textproc/btparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
