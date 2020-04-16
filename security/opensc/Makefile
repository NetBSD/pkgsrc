# $NetBSD: Makefile,v 1.30 2020/04/16 12:37:51 manu Exp $

OPENSC_PKG_VERSION=	0.20.0
DISTNAME=		opensc-${OPENSC_PKG_VERSION}
#PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=opensc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenSC/OpenSC/wiki
COMMENT=		Smart Card drivers and middleware
LICENSE=		gnu-lgpl-v2.1

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config
WRKSRC=			${WRKDIR}/OpenSC-${OPENSC_PKG_VERSION}

USE_TOOLS+=		autoreconf autoconf automake
AUTOCONF_REQD=		2.60
AUTOMAKE_REQD=		1.15
pre-configure:
	cd ${WRKSRC:Q} && \
	./bootstrap \
		-s ${OPENSC_VERSION_SUFFIX:Q} \
		-r ${OPENSC_VERSION_REVISION:Q}

.include "options.mk"

# Previous versions needed these, but 0.12.2 configure does not
# recognize them.
#CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
#CONFIGURE_ARGS+=	--disable-sensitive-logging

# Is this necessary (and non-default)?
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

# This is perhaps an upstream bug.
CONFIGURE_ENV+=		PCSC_CFLAGS=-I${PREFIX}/include/PCSC

# The stylesheets are not found without this.
CONFIGURE_ARGS+=	--with-xsl-stylesheetsdir=${PREFIX}/share/xsl/docbook

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf.example ${DESTDIR}${EGDIR}/opensc.conf

# build tools for doc; should be TOOLS
.include "../../textproc/libxslt/buildlink3.mk"

# We avoid pthreads intentionally; tell dlopen not drag it in.
DLOPEN_REQUIRE_PTHREADS=	no
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
