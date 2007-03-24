# $NetBSD: Makefile,v 1.18 2007/03/24 17:58:04 kristerw Exp $

DISTNAME=		darcs-1.0.8
PKGREVISION=		2
CATEGORIES=		devel scm
MASTER_SITES=		http://www.darcs.net/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.darcs.net/
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
