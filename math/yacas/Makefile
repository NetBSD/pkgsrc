# $NetBSD: Makefile,v 1.14 2004/10/03 00:12:57 tv Exp $
#

DISTNAME=	yacas-1.0.56
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://yacas.sourceforge.net/backups/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://yacas.sourceforge.net
COMMENT=	Yet Another Computer Algebra System

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_GCC_SHLIB=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
USE_X11=	YES
USE_PERL5=	build

TEST_TARGET=	test

LDFLAGS+=	-Wl,-R${PREFIX}/lib/yacas

# dos2unix fix on a few files
pre-patch:
.for __tmp__ in src/cyacas.h src/cyacas.cpp plugins/pcre/pcre_config.h
	${MV} ${WRKSRC}/${__tmp__} ${WRKSRC}/${__tmp__}.bak
	${CAT} ${WRKSRC}/${__tmp__}.bak | ${TR} -d "\015" >  \
		${WRKSRC}/${__tmp__}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yacas.sh ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/emacs/site-lisp
.for __tmp__ in yacas.el yacas-names.el yacas-functions.el yacas-notebook.el \
	yacas-notebook.sty font-latex.el
	${INSTALL_DATA} ${WRKSRC}/YacasNotebook/${__tmp__} ${PREFIX}/share/emacs/site-lisp
.endfor

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
