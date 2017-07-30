# $NetBSD: Makefile,v 1.5 2017/07/30 22:45:42 wiz Exp $

DISTNAME=	ABC2PS-${ABC2PSVER}
PKGNAME=	abc2ps-${ABC2PSVER}
CATEGORIES=	print
MASTER_SITES=	# http://www.ihp-ffo.de/~msm/abc_src/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ihp-ffo.de/~msm/
COMMENT=	Music typesetting program for abc

ABC2PSVER=	1.3.3

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin share/doc/abc2ps share/examples/abc2ps

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o abc2ps abc2ps.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abc2ps ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} Changes License New.Features \
		ReadMe.abc2ps layout.txt ${DESTDIR}${PREFIX}/share/doc/abc2ps/
	cd ${WRKSRC} && ${INSTALL_DATA} bach.abc blue_boy_bass.abc \
		bran5.abc celloprelude.abc desafinado.abc fbook.fmt \
		fonts.fmt journey.abc landscape.fmt mtunes1.abc \
		newfeatures.abc sample.abc scotland.abc trio.abc \
		voices.abc ${DESTDIR}${PREFIX}/share/examples/abc2ps/

.include "../../mk/bsd.pkg.mk"
