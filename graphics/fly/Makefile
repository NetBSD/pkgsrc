# $NetBSD: Makefile,v 1.64 2022/06/28 11:34:00 wiz Exp $

DISTNAME=	fly-1.6.5
PKGREVISION=	35
CATEGORIES=	graphics www
MASTER_SITES=	# ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html
COMMENT=	Command-file interface for creating and modifying PNG images

BUILD_DEPENDS+=	gif2png>=2.4.2:../../graphics/gif2png

USE_TOOLS+=	perl:run
REPLACE_PERL=	examples/cgi-perl-example.pl \
		examples/fly-tester.pl \
		examples/size.pl \
		examples/perl.example

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	examples/cgi-perl-example.pl
SUBST_VARS.prefix=	PREFIX

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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
