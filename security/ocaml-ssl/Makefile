# $NetBSD: Makefile,v 1.1.1.1 2007/01/15 14:21:10 tonio Exp $
#

DISTNAME=	ocaml-ssl-0.4.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=savonet/}

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://savonet.sourceforge.net/wiki/OCamlLibs
COMMENT=	SSL library for OCaml

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
BUILD_TARGET+=	all

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SRC+=	PLIST.opt
.endif

PLIST_SRC+=	PLIST



.include "../../lang/ocaml/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
