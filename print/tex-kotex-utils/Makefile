# $NetBSD: Makefile,v 1.2 2011/01/12 15:18:12 minskim Exp $

DISTNAME=	kotex-util-source-20100509
PKGNAME=	tex-kotex-utils-0.2
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	Utilities for tex-kotex

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}

REPLACE_PERL=	scripts/kotex-util/perl/*.pl

INSTALLATION_DIRS+=	bin

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

.include "../../mk/bsd.pkg.mk"
