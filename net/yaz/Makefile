# $NetBSD: Makefile,v 1.29 2010/02/04 11:17:06 wiz Exp $
#

DISTNAME=	yaz-4.0.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	phil@NetBSD.org
HOMEPAGE=	http://indexdata.dk/yaz/
COMMENT=	C/C++ toolkit for the development of Z39.50v3/SRW clients and servers
LICENSE=	modified-bsd

# needed during installation
BUILD_DEPENDS+=	tcl-[0-9]*:../../lang/tcl

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.libiconv}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-xml2=${BUILDLINK_PREFIX.libxml2}

PTHREAD_OPTS+=	native optional

# don't depend on tcl, but fix the path to tclsh anyway
CHECK_INTERPRETER_SKIP=	util/yaz-asncomp
SUBST_CLASSES+=		tclsh
SUBST_SED.tclsh+=	-e 's,/usr/bin/tclsh,${PREFIX}/bin/tclsh,'
SUBST_FILES.tclsh+=	util/yaz-asncomp
SUBST_STAGE.tclsh+=	post-build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
