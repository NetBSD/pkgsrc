# $NetBSD: Makefile,v 1.77 2020/04/12 08:28:04 adam Exp $
#

DISTNAME=	yaz-4.1.6
DISTNAME=	yaz-5.16.0
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	phil@NetBSD.org
HOMEPAGE=	https://www.indexdata.com/yaz/
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers
LICENSE=	modified-bsd

#In file included from marcdisp.c:24:
#In file included from ../include/yaz/marcdisp.h:42:
#../include/yaz/z-opac.h:37:2: error: unknown type name 'Z_External'
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config tclsh
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-xml2=${BUILDLINK_PREFIX.libxml2}

# backtrace and backtrace_symbols
.include "../../mk/bsd.prefs.mk"
# DragonFly too ?
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
LDFLAGS+=	-lexecinfo
.endif

PTHREAD_OPTS+=	native optional

# don't depend on tcl, but fix the path to tclsh anyway
CHECK_INTERPRETER_SKIP=	bin/yaz-asncomp
REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*tclsh
REPLACE.tclsh.new=	${TCLSH}
REPLACE_FILES.tclsh=	util/yaz-asncomp

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
