# $NetBSD: Makefile,v 1.1.1.1 2002/03/22 15:34:02 wiz Exp $
#

DISTNAME=	clara-0.9.8
CATEGORIES=	graphics textproc
MASTER_SITES=	ftp://carroll.cac.psu.edu/pub/linux/distributions/mandrake-devel/projects/claraocr/ \
		ftp://ftp.wtfo.com/pub/linux/Mandrake-devel/projects/claraocr/ \
		ftp://gd.tuwien.ac.at/pub/linux/Mandrake-devel/projects/claraocr/ \
		ftp://mandrake.redbox.cz/Mandrake-devel/projects/claraocr/ \
		ftp://ftp.proxad.net/pub/Distributions_Linux/Mandrake-devel/projects/claraocr/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://www.claraocr.org/
COMMENT=	Optical Character Recognition (OCR) program for books

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

USE_PERL5=		YES
REPLACE_PERL=		clara.pl mkdoc.pl selthresh.pl
USE_BUILDLINK_ONLY=	YES

# install a example input file
post-install:
	${INSTALL_DATA} ${WRKSRC}/imre.pbm ${PREFIX}/share/doc/clara

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
