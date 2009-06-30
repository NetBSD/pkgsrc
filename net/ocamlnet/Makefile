# $NetBSD: Makefile,v 1.2 2009/06/30 00:07:21 joerg Exp $
#

DISTNAME=		ocamlnet-1.1.2
CATEGORIES=		net
MASTER_SITES=		http://www.ocaml-programming.de/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ocaml-programming.de/packages/
COMMENT=		Library focusing on application-level network protocols (OCaml)

MAKE_JOBS_SAFE=		no

DEPENDS+=		pcre-ocaml-[0-9]*:../../devel/pcre-ocaml
DEPENDS+=		equeue-[0-9]*:../../devel/equeue

HAS_CONFIGURE=		yes
CONFIGURE_DIRS=		src
USE_TOOLS+=		gmake
BUILD_TARGET=		all opt
PLIST_SRC=		PLIST.opt PLIST

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
