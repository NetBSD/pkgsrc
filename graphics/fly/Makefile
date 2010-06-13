# $NetBSD: Makefile,v 1.37 2010/06/13 22:44:30 wiz Exp $

DISTNAME=	fly-1.6.5
PKGREVISION=	11
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html
COMMENT=	Command-file interface for creating and modifying PNG images

BUILD_DEPENDS+=	gif2png>=2.4.2:../../graphics/gif2png

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
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
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fly
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/fly
	cd ${WRKSRC}/doc; ${LOCALBASE}/bin/gif2png *.gif
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.png \
		${DESTDIR}${PREFIX}/share/doc/fly
	${RM} -f ${WRKSRC}/examples/*.orig
	cd ${WRKSRC}/examples; ${INSTALL_DATA} * \
		${DESTDIR}${PREFIX}/share/examples/fly

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
