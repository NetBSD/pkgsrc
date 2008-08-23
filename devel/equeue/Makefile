# $NetBSD: Makefile,v 1.2 2008/08/23 02:09:28 epg Exp $
#

DISTNAME=		equeue-2.1.3
CATEGORIES=		devel
MASTER_SITES=		http://www.ocaml-programming.de/packages/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ocaml-programming.de/packages/
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
