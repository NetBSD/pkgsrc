# $NetBSD: Makefile,v 1.5 2005/11/08 18:50:03 tonio Exp $

DISTNAME=		darcs-1.0.3
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		augustss@NetBSD.org
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Distributed revision control system

BUILD_DEPENDS+=		latex2html>=2002.2.1nb3:../../textproc/latex2html

LATEX_DEPMETHOD=	build
USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/latex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
