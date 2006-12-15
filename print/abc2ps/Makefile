# $NetBSD: Makefile,v 1.2 2006/12/15 14:34:20 wiz Exp $
#

DISTNAME=	ABC2PS-${ABC2PSVER}
PKGNAME=	abc2ps-${ABC2PSVER}
CATEGORIES=	print
MASTER_SITES=	http://www.ihp-ffo.de/~msm/abc_src/
EXTRACT_SUFX=	.tar.Z
WRKSRC=		${WRKDIR}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ihp-ffo.de/~msm/
COMMENT=	Music typesetting program for abc

ABC2PSVER=	1.3.3

do-build:
	cd ${WRKSRC} && ${CC} -o abc2ps abc2ps.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/abc2ps
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/abc2ps
	${INSTALL_PROGRAM} ${WRKSRC}/abc2ps ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} Changes License New.Features \
		ReadMe.abc2ps layout.txt ${PREFIX}/share/doc/abc2ps/
	cd ${WRKSRC} && ${INSTALL_DATA} bach.abc blue_boy_bass.abc \
		bran5.abc celloprelude.abc desafinado.abc fbook.fmt \
		fonts.fmt journey.abc landscape.fmt mtunes1.abc \
		newfeatures.abc sample.abc scotland.abc trio.abc \
		voices.abc ${PREFIX}/share/examples/abc2ps/

.include "../../mk/bsd.pkg.mk"
