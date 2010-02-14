# $NetBSD: Makefile,v 1.4 2010/02/14 20:51:23 joerg Exp $
#

DISTNAME=		equeue-2.1.3
CATEGORIES=		devel
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.camlcity.org/
COMMENT=		Queues for file events (OCaml)

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		all opt
PLIST_SRC=		PLIST.opt PLIST

INSTALLATION_DIRS+=	lib/ocaml/site-lib

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
