# $NetBSD: Makefile,v 1.15 2013/11/01 11:11:18 jaapb Exp $
#

DISTNAME=		ocamlnet-3.7.3
CATEGORIES=		net
MASTER_SITES=		http://download.camlcity.org/download/

MAINTAINER=		jaapb@NetBSD.org
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

.include "../../mk/bsd.prefs.mk"

PLIST_VARS=		opt ssl xti
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=		opt
PLIST.opt=		yes
.endif
.if ${OPSYS} == "SunOS"
PLIST.xti=		yes
.endif

SUBPKGDIRS=		equeue netcgi2-plex netplex pop rpc-ssl equeue-ssl \
			netclient netshm rpc shell netcamlbox netgssapi \
			netstring rpc-auth-local smtp netcgi2 netmulticore \
			netsys rpc-generator rpc-xti

INSTALLATION_DIRS=	lib/ocaml/site-lib

pre-install:
.for i in ${SUBPKGDIRS};
	${RM} -rf ${DESTDIR}/${PREFIX}/lib/ocaml/site-lib/${i}
.endfor

.include "options.mk"
.include "../../devel/pcre-ocaml/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
