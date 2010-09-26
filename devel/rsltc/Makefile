# $NetBSD: Makefile,v 1.13 2010/09/26 11:03:05 obache Exp $
#

DISTNAME=		rsltcsrc
PKGNAME=		rsltc-2.4
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.iist.unu.edu/newrh/III/3/1/docs/rsltc/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		MarkoSchuetz@web.de
HOMEPAGE=		http://www.iist.unu.edu/newrh/III/3/1/page.html
COMMENT=		RAISE Specification Language Type Checker

DEPENDS+=		gentle>=97:../../devel/gentle

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=		make_sunos
USE_TOOLS+=		bison gmake lex
WRKSRC=			${WRKDIR}/rsl.2.4
INSTALLATION_DIRS=	bin

MAKE_FLAGS+=		LEX=${LEX}

MAKE_JOBS_SAFE=		no

post-extract:
	${CP} ${FILESDIR}/path.el ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rsltc ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/emacs/site-lisp/rsl
	(cd ${WRKSRC} ; for i in rsltc.el tokenise.el rslconvert.el rsl-mode.el ; do\
		${EMACS_BIN} -batch -l path.el -f batch-byte-compile $$i ;\
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/share/emacs/site-lisp/rsl ;\
		${INSTALL_DATA} $${i}c ${DESTDIR}${PREFIX}/share/emacs/site-lisp/rsl ;\
	done)

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
