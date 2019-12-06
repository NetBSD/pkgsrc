# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:22 markd Exp $

DISTNAME=	featpost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.8.8
TEXLIVE_REV=	35346

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/featpost
COMMENT=	Documentation for tex-featpost
LICENSE=	gnu-gpl-v2

REPLACE_SH+=	doc/metapost/featpost/bash/COMPILE.sh
REPLACE_SH+=	doc/metapost/featpost/bash/laproof.sh
REPLACE_SH+=	doc/metapost/featpost/bash/makehtmlindex.sh

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
