# $NetBSD: Makefile,v 1.1.1.1 2006/08/11 15:43:36 wiz Exp $
#

DISTNAME=		ocamlnet-1.1.2
CATEGORIES=		net
MASTER_SITES=		http://www.ocaml-programming.de/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ocaml-programming.de/packages/
COMMENT=		Library focusing on application-level network protocols (OCaml)

DEPENDS+=		pcre-ocaml-[0-9]*:../../devel/pcre-ocaml
DEPENDS+=		equeue-[0-9]*:../../devel/equeue

HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		src
USE_TOOLS+=		gmake
BUILD_TARGET=		all opt
PLIST_SRC=		PLIST.opt PLIST

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
