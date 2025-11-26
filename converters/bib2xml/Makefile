# $NetBSD: Makefile,v 1.19 2025/11/26 08:30:25 wiz Exp $

DISTNAME=	bib2xml-10062002
PKGNAME=	${DISTNAME:C/-(....)(....)/-\2\1/}
PKGREVISION=	4
CATEGORIES=	converters textproc
#MASTER_SITES=	http://www-plan.cs.colorado.edu/henkel/stuff/bib2xml/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www-plan.cs.colorado.edu/henkel/stuff/bib2xml/
COMMENT=	BibTeX to XML converter

WRKSRC=		${WRKDIR}/bib2xml
GNU_CONFIGURE=	YES
BUILD_DIRS=	progs
TOOLS_BROKEN+=	perl

INSTALLATION_DIRS=	bin

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/perl5/vendor_perl/lib64 -L${PREFIX}/lib/perl5/vendor_perl/lib64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/progs/bib2xml ${DESTDIR}${PREFIX}/bin

.include "../../textproc/p5-Text-BibTeX/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
