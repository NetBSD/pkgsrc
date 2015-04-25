# $NetBSD: Makefile,v 1.21 2015/04/25 14:23:47 tnn Exp $
#

DISTNAME=		ocamlnet-3.7.7
PKGNAME=	${DISTNAME} # in order to avoid prefixing with ocaml-
PKGREVISION=	2
CATEGORIES=		net
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://projects.camlcity.org/projects/ocamlnet.html
COMMENT=		Library focusing on application-level network protocols (OCaml)
LICENSE=		zlib AND gnu-gpl-v2

MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-without-nethttpd -without-rpc-auth-dh -disable-tcl \
	-disable-apache -enable-pcre
USE_TOOLS+=		gmake
BUILD_TARGET=		all
OCAML_USE_FINDLIB=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		ssl xti
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=		opt
.endif
.if ${OPSYS} == "SunOS"
PLIST.xti=		yes
.endif

.include "options.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
