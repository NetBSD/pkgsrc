# $NetBSD: Makefile,v 1.7 2006/09/09 02:41:58 obache Exp $
#

DISTNAME=		rsltcsrc
PKGNAME=		rsltc-2.4
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.iist.unu.edu/newrh/III/3/1/docs/rsltc/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		MarkoSchuetz@web.de
HOMEPAGE=		http://www.iist.unu.edu/newrh/III/3/1/page.html
COMMENT=		RAISE Specification Language Type Checker

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
DEPENDS+=		gentle>=97:../../devel/gentle

MAKE_FILE=		make_sunos
USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/rsl.2.4
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsltc ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp/rsl
	(cd ${WRKSRC} ; for i in rsltc.el tokenise.el rslconvert.el rsl-mode.el ; do\
		${EMACS_BIN} -batch -f batch-byte-compile $$i ;\
		${INSTALL_DATA} $$i ${PREFIX}/share/emacs/site-lisp/rsl ;\
		${INSTALL_DATA} $${i}c ${PREFIX}/share/emacs/site-lisp/rsl ;\
	done)

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
