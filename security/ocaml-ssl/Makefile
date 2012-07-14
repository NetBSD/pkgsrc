# $NetBSD: Makefile,v 1.8 2012/07/14 21:23:49 wiz Exp $
#

DISTNAME=	ocaml-ssl-0.4.6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=savonet/}

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://savonet.sourceforge.net/wiki/OCamlLibs
COMMENT=	SSL library for OCaml
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
BUILD_TARGET+=	all

.include "../../mk/bsd.prefs.mk"

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
