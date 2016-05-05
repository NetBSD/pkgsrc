# $NetBSD: Makefile,v 1.30 2016/05/05 16:04:21 jaapb Exp $
#

DISTNAME=		ocamlnet-4.1.1
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
	${OCAML_SITELIBDIR}/equeue ${OCAML_SITELIBDIR}/netcamlbox \
	${OCAML_SITELIBDIR}/netcgi2-plex ${OCAML_SITELIBDIR}/netcgi2 \
	${OCAML_SITELIBDIR}/netclient ${OCAML_SITELIBDIR}/netmulticore \
	${OCAML_SITELIBDIR}/netplex ${OCAML_SITELIBDIR}/netshm \
	${OCAML_SITELIBDIR}/netstring-pcre ${OCAML_SITELIBDIR}/netstring \
	${OCAML_SITELIBDIR}/netsys ${OCAML_SITELIBDIR}/netunidata \
	${OCAML_SITELIBDIR}/netzip ${OCAML_SITELIBDIR}/rpc-auth-local \
	${OCAML_SITELIBDIR}/rpc-generator ${OCAML_SITELIBDIR}/rpc

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		xti
.if ${OCAML_USE_OPT_COMPILER} == "yes"
BUILD_TARGET+=		opt
.endif
.if ${OPSYS} == "SunOS"
PLIST.xti=		yes
OCAML_FINDLIB_DIRS+=	${OCAML_SITELIBDIR}/rpc-xti
.endif

.include "options.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../archivers/ocaml-zip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
