# $NetBSD: Makefile,v 1.2 2005/05/22 20:07:50 jlam Exp $

DISTNAME=		darcs-1.0.2
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		augustss@NetBSD.org
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		A distributed revision control system

BUILD_DEPENDS+=		teTeX>=2.0.2nb1:../../print/teTeX
BUILD_DEPENDS+=		latex2html>=2002.2.1nb3:../../textproc/latex2html

USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--without-libcurl


.include "../../www/curl/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
