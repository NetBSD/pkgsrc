# $NetBSD: Makefile,v 1.55 2014/01/01 11:52:03 wiz Exp $
#

DISTNAME=	yaz-4.1.6
PKGREVISION=	11
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	phil@NetBSD.org
HOMEPAGE=	https://www.indexdata.com/yaz/
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers
LICENSE=	modified-bsd

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config tclsh
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-xml2=${BUILDLINK_PREFIX.libxml2}

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
