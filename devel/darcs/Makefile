# $NetBSD: Makefile,v 1.14 2006/09/09 02:41:57 obache Exp $

DISTNAME=		darcs-1.0.4
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Distributed revision control system

BUILD_DEPENDS+=		latex2html>=2002.2.1nb3:../../textproc/latex2html

TEX_DEPMETHOD=		build
USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile
GNU_CONFIGURE=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
