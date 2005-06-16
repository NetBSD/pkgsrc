# $NetBSD: Makefile,v 1.29 2005/06/16 06:57:57 jlam Exp $

DISTNAME=	fly-1.6.5
PKGREVISION=	6
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html
COMMENT=	Command-file interface for creating and modifying PNG images

BUILD_DEPENDS+=	gif2png>=2.4.2:../../graphics/gif2png

USE_PERL5=	YES

REPLACE_PERL=	examples/cgi-perl-example.pl \
		examples/fly-tester.pl \
		examples/size.pl \
		examples/perl.example

INSTALLATION_DIRS=	bin

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

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
