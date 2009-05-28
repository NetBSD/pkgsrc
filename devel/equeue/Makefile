# $NetBSD: Makefile,v 1.3 2009/05/28 21:06:08 zafer Exp $
#

DISTNAME=		equeue-2.1.3
CATEGORIES=		devel
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.camlcity.org/
COMMENT=		Queues for file events (OCaml)

MAKE_JOBS_SAFE=		no

DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		all opt
PLIST_SRC=		PLIST.opt PLIST

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
