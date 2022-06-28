# $NetBSD: Makefile,v 1.29 2022/06/28 11:33:59 wiz Exp $

DISTNAME=	clara-0.9.9
PKGNAME=	${DISTNAME:S/clara/claraocr/}
PKGREVISION=	12
CATEGORIES=	graphics textproc
MASTER_SITES=	ftp://carroll.cac.psu.edu/pub/linux/distributions/mandrake-devel/projects/claraocr/
MASTER_SITES+=	ftp://ftp.wtfo.com/pub/linux/Mandrake-devel/projects/claraocr/
MASTER_SITES+=	ftp://mandrake.redbox.cz/Mandrake-devel/projects/claraocr/
MASTER_SITES+=	ftp://ftp.proxad.net/pub/Distributions_Linux/Mandrake-devel/projects/claraocr/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://geocities.ws/claraocr/
COMMENT=	Optical Character Recognition (OCR) program for books

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

USE_TOOLS+=	perl:run
REPLACE_PERL=	clara.pl mkdoc.pl selthresh.pl

CONFLICTS+=	clara-[0-9]*

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/clara

# install a example input file
post-install:
	${INSTALL_DATA} ${WRKSRC}/imre.pbm ${DESTDIR}${PREFIX}/share/doc/clara

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
