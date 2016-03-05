# $NetBSD: Makefile,v 1.24 2016/03/05 11:29:22 jperkin Exp $

OPENSC_PKG_VERSION=	0.15.0
DISTNAME=		opensc-${OPENSC_PKG_VERSION}
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opensc/OpenSC/opensc-0.13.0/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/OpenSC/OpenSC/wiki
COMMENT=		Smart Card drivers and middleware
LICENSE=		gnu-lgpl-v2.1

BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES
USE_TOOLS+=		gmake pkg-config

USE_TOOLS+=		autoreconf autoconf automake
AUTOCONF_REQD=		2.60
AUTOMAKE_REQD=		1.10
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
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

# build tools for doc; should be TOOLS
.include "../../textproc/libxslt/buildlink3.mk"

# We avoid pthreads intentionally; tell dlopen not drag it in.
DLOPEN_REQUIRE_PTHREADS=	no
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
