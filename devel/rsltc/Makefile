# $NetBSD: Makefile,v 1.10 2008/10/11 09:31:55 uebayasi Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=		make_sunos
USE_TOOLS+=		gmake lex
WRKSRC=			${WRKDIR}/rsl.2.4
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsltc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/emacs/site-lisp/rsl
	(cd ${WRKSRC} ; for i in rsltc.el tokenise.el rslconvert.el rsl-mode.el ; do\
		${EMACS_BIN} -batch -f batch-byte-compile $$i ;\
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/share/emacs/site-lisp/rsl ;\
		${INSTALL_DATA} $${i}c ${DESTDIR}${PREFIX}/share/emacs/site-lisp/rsl ;\
	done)

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
