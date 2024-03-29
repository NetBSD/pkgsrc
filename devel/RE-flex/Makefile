# $NetBSD: Makefile,v 1.7 2024/03/21 20:44:40 wiz Exp $

DISTNAME=	RE-flex-4.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Genivia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Genivia/RE-flex/
COMMENT=	Fast lexical analyzer generator for C++ with full Unicode support
LICENSE=	modified-bsd

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

INSTALLATION_DIRS+=	bin lib share/doc/RE-flex include/reflex ${PKGMANDIR}/man1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake sed
USE_LIBTOOL=	yes

do-build:
	cd ${WRKSRC}/lib && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/src/reflex ${DESTDIR}${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/lib/libreflex.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/lib/libreflexmin.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/reflex/*.h \
		${DESTDIR}${PREFIX}/include/reflex
	${INSTALL_MAN} ${WRKSRC}/doc/man/reflex.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install: post-install-doxygen post-install-examples
.for f in README.md LICENSE.txt CONTRIBUTING.md CODE_OF_CONDUCT.md lex.vim
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/RE-flex
.endfor

.include "../../mk/bsd.pkg.mk"
