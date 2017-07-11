# $NetBSD: Makefile,v 1.38 2017/07/11 14:11:57 jaapb Exp $
#

DISTNAME=		ocamlnet-4.1.2
PKGREVISION=		4
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
OCAML_FINDLIB_DIRS= \
	equeue netcamlbox netcgi2-plex netcgi2 netclient netmulticore \
	netplex netshm netstring-pcre netstring netsys netunidata \
	netzip rpc-auth-local rpc-generator rpc

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		xti
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=		opt
MAKE_ENV+=		HAVE_SHARED=1
.endif
.if ${OPSYS} == "SunOS"
PLIST.xti=		yes
OCAML_FINDLIB_DIRS+=	rpc-xti
.endif

.include "options.mk"

.if !empty(PKG_OPTIONS:Mcmxs)
post-build:
	for i in ${OCAML_FINDLIB_DIRS}; do \
		cd ${WRKSRC}/src/$$i && \
		for j in *.cmxa; do \
			k=`echo $$j | sed -e 's/cmxa$$/cmxs$$/'`; \
			ocamlopt -linkall -shared -o $$k $$j; \
		done; \
	done
.endif

.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
