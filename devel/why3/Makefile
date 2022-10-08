# $NetBSD: Makefile,v 1.1 2022/10/08 16:36:47 tonio Exp $

DISTNAME=	why3-1.5.1
CATEGORIES=	devel
MASTER_SITES=	https://why3.gitlabpages.inria.fr/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://why3.lri.fr/
COMMENT=	Platform for deductive program verification
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	menhir-[0-9]*:../../devel/menhir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=		--disable-ide

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
