# $NetBSD: Makefile,v 1.22 2003/07/21 16:51:39 martti Exp $

DISTNAME=	fly-1.6.5
PKGREVISION=	4
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html
COMMENT=	Command-file interface for creating and modifying PNG images

BUILD_DEPENDS+=	gif2png>=2.4.2:../../graphics/gif2png

USE_BUILDLINK2=	YES
USE_PERL5=	YES
USE_X11=	YES

REPLACE_PERL=	${WRKSRC}/examples/cgi-perl-example.pl \
		${WRKSRC}/examples/fly-tester.pl \
		${WRKSRC}/examples/size.pl \
		${WRKSRC}/examples/perl.example

pre-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/examples/cgi-perl-example.pl \
		> ${WRKSRC}/examples/cgi-perl-example.pl.new
	${MV} ${WRKSRC}/examples/cgi-perl-example.pl.new \
		${WRKSRC}/examples/cgi-perl-example.pl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fly
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/fly
	cd ${WRKSRC}/doc; ${LOCALBASE}/bin/gif2png *.gif
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.png ${PREFIX}/share/doc/fly
	${RM} -f ${WRKSRC}/examples/*.orig
	cd ${WRKSRC}/examples; ${INSTALL_DATA} * ${PREFIX}/share/examples/fly

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
