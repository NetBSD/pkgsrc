# $NetBSD: Makefile,v 1.25 2012/10/02 20:11:48 asau Exp $

DISTNAME=		pforth_v27_20101121
PKGNAME=		pforth-27
CATEGORIES=		lang
MASTER_SITES=		http://pforth.googlecode.com/files/
EXTRACT_SUFX=		.zip

MAINTAINER=		asau@NetBSD.org
HOMEPAGE=		http://www.softsynth.com/pforth/
COMMENT=		Portable ANS-like Forth
LICENSE=		mit

WRKSRC=			$(WRKDIR)/pforth_v27
MAKE_FILE=		build/unix/Makefile
MAKE_FLAGS=		SRCDIR=.
CPPFLAGS=		-DPF_DEFAULT_DICTIONARY='"$(PREFIX)/lib/pforth/pforth.dic"'

INSTALLATION_DIRS=	bin lib/pforth share/doc/pforth share/pforth share/pforth/utils

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pforth ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pforth.dic ${DESTDIR}${PREFIX}/lib/pforth
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/pforth/
	${INSTALL_DATA} ${WRKSRC}/fth/*.fth ${DESTDIR}${PREFIX}/share/pforth/
	${INSTALL_DATA}  ${WRKSRC}/fth/utils/*.fth			\
		${DESTDIR}${PREFIX}/share/pforth/utils/

.include "../../mk/bsd.pkg.mk"
