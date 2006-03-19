# $NetBSD: Makefile,v 1.11 2006/03/19 15:54:13 wiz Exp $

DISTNAME=		darcs-1.0.4
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		augustss@NetBSD.org
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Distributed revision control system

BUILD_DEPENDS+=		latex2html>=2002.2.1nb3:../../textproc/latex2html

TEX_DEPMETHOD=		build
USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
# gmp should be implied by ghc, but isn't (PR 33100)
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
