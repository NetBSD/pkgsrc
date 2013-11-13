# $NetBSD: Makefile,v 1.7 2013/11/13 19:27:55 minskim Exp $

DISTNAME=	kotex-dist-20110504
PKGNAME=	tex-kotex-utils-0.3
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	kotexindy.pl utf8.xdy
SITES.kotexindy.pl= \
http://ftp.ktug.or.kr/pub/ktug/texlive/texmf-dist/scripts/kotex-util/perl/
SITES.utf8.xdy= \
http://ftp.ktug.or.kr/pub/ktug/texlive/texmf/xindy/modules/lang/korean/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	Utilities for tex-kotex

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}

REPLACE_PERL=	*.pl scripts/kotex-util/perl/*.pl

INSTALLATION_DIRS+=	bin share/texmf-dist/xindy/modules/lang/korean

.include "../../print/kpathsea/texmf.mk"

do-build:
.for f in hbibtex hmakeindex
	cd ${WRKSRC}/source/latex/kotex-util && \
	${CC} ${CPPFLAGS} ${CFLAGS} -o ${f} ${f}.c
.endfor

do-install:
.for f in hbibtex hmakeindex
	${INSTALL_PROGRAM} ${WRKSRC}/source/latex/kotex-util/${f} \
		${DESTDIR}${PREFIX}/bin
.endfor
.for f in euc-bookmark hypua2jamo insertjamofiller jamo2hypua komkindex \
	ttf2kotexfont
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/kotex-util/perl/${f}.pl \
		${DESTDIR}${PREFIX}/bin/${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/kotexindy.pl \
		${DESTDIR}${PREFIX}/bin/kotexindy
	${INSTALL_DATA} ${WRKSRC}/utf8.xdy \
		${DESTDIR}${PREFIX}/share/texmf-dist/xindy/modules/lang/korean/

.include "../../mk/bsd.pkg.mk"
