# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:24 rillig Exp $

DISTNAME=	featpost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.8.8
TEXLIVE_REV=	35346

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/featpost
COMMENT=	Documentation for tex-featpost
LICENSE=	gnu-gpl-v2

REPLACE_SH+=	doc/metapost/featpost/bash/COMPILE.sh
REPLACE_SH+=	doc/metapost/featpost/bash/laproof.sh
REPLACE_SH+=	doc/metapost/featpost/bash/makehtmlindex.sh

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
