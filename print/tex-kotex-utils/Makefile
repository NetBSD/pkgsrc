# $NetBSD: Makefile,v 1.1.1.1 2010/05/03 23:17:48 minskim Exp $

DISTNAME=	ko.tex-macro
PKGNAME=	tex-kotex-utils-0.1.1
CATEGORIES=	print
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/ko.TeX/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	Utilities for tex-kotex

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run
WRKSRC=		${WRKDIR}/util

REPLACE_PERL=	*.pl

INSTALLATION_DIRS+=	bin

do-build:
.for f in hbibtex hmakeindex
	cd ${WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} -o ${f} ${f}.c
.endfor

do-install:
.for f in hbibtex hmakeindex
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in euc-bookmark hypua2jamo insertjamofiller jamo2hypua komkindex \
	ttf2kotexfont
	${INSTALL_SCRIPT} ${WRKSRC}/${f}.pl ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
