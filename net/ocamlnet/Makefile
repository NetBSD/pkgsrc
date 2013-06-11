# $NetBSD: Makefile,v 1.12 2013/06/11 14:50:43 jaapb Exp $
#

DISTNAME=		ocamlnet-3.6.5
CATEGORIES=		net
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		jaapb@kerguelen.org
HOMEPAGE=		http://projects.camlcity.org/projects/ocamlnet.html
COMMENT=		Library focusing on application-level network protocols (OCaml)
LICENSE=		zlib AND gnu-gpl-v2

MAKE_JOBS_SAFE=		no

DEPENDS+=		ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-without-nethttpd -without-rpc-auth-dh -disable-gtk2 \
			-disable-tcl -disable-apache -enable-pcre
USE_TOOLS+=		gmake
BUILD_TARGET=		all

PLIST_VARS=		opt ssl
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=		opt
PLIST.opt=		yes
.endif

SUBPKGDIRS=		equeue netcgi2-plex netplex pop rpc-ssl equeue-ssl \
			netclient netshm rpc shell netcamlbox netgssapi \
			netstring rpc-auth-local smtp netcgi2 netmulticore \
			netsys rpc-generator

INSTALLATION_DIRS=	lib/ocaml/site-lib

pre-install:
.for i in ${SUBPKGDIRS};
	${RM} -rf ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib/${i}
.endfor

.include "options.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
