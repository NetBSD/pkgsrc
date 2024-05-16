# $NetBSD: Makefile,v 1.96 2024/05/16 06:15:22 wiz Exp $
#

DISTNAME=		ocamlnet-4.1.9
PKGREVISION=		12
CATEGORIES=		net
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://projects.camlcity.org/projects/ocamlnet.html
COMMENT=		Library focusing on application-level network protocols (OCaml)
LICENSE=		zlib AND gnu-gpl-v2

MAKE_JOBS_SAFE=	no

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-without-nethttpd -disable-tcl -disable-apache \
			-enable-pcre -enable-zip
USE_TOOLS+=		gmake
BUILD_TARGET=		all
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	\
	equeue netcamlbox netcgi2-plex netcgi2 netclient netmulticore \
	netplex netshm netstring-pcre netstring netsys netunidata \
	netzip rpc-auth-local rpc-generator rpc

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		xti
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=		opt
.endif
.if ${OPSYS} == "SunOS"
PLIST.xti=		yes
OCAML_FINDLIB_DIRS+=	rpc-xti
.endif

.include "options.mk"

.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
