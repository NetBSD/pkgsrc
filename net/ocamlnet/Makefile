# $NetBSD: Makefile,v 1.4 2010/01/30 19:43:18 joerg Exp $
#

DISTNAME=		ocamlnet-1.1.2
CATEGORIES=		net
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://projects.camlcity.org/projects/ocamlnet.html
COMMENT=		Library focusing on application-level network protocols (OCaml)

PKG_DESTDIR_SUPPORT=	user-destdir

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
