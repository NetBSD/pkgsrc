# $NetBSD: Makefile,v 1.2 2006/03/02 20:33:49 rpaulo Exp $

DISTNAME=	cflow-1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=cflow/}

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cflow/
COMMENT=	Code-path flow analyzer for C

GNU_CONFIGURE=		YES
USE_TOOLS+=		yacc lex

SUBST_CLASSES+=		emacs
SUBST_MESSAGE.emacs=	Removing cflow Emacs mode
SUBST_STAGE.emacs=	pre-configure
SUBST_FILES.emacs=	Makefile.in
SUBST_SED.emacs=	-e 's| elisp||g'

INFO_FILES=		cflow.info

.include "../../mk/bsd.pkg.mk"
