# $NetBSD: Makefile,v 1.18 2014/02/12 23:18:34 tron Exp $

OPENSC_PKG_VERSION=	0.12.2
DISTNAME=		opensc-${OPENSC_PKG_VERSION}
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/opensc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opensc-project.org/opensc/
COMMENT=		Smart Card drivers and middleware
LICENSE=		gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_OLD_DES_API=	YES
USE_TOOLS+=		gmake pkg-config

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
CONFIGURE_ARGS+=	--with-xsl-stylesheetsdir=${BUILDLINK_PREFIX.docbook-xsl}/share/xsl/docbook

EGDIR=			${PREFIX}/share/examples/opensc
CONF_FILES+=		${EGDIR}/opensc.conf ${PKG_SYSCONFDIR}/opensc.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/opensc.conf ${DESTDIR}${EGDIR}

# build tools for doc; should be TOOLS
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/docbook-xsl/buildlink3.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
