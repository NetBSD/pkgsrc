# $NetBSD: Makefile,v 1.30 2026/05/11 09:23:51 adam Exp $

DISTNAME=	sysbench-1.0.20
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_GITHUB:=akopytov/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/akopytov/sysbench
COMMENT=	Modular, cross-platform and multi-threaded benchmark tool
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # xsltproc

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-system-ck
CONFIGURE_ARGS+=	--with-system-luajit
CONFIGURE_ENV+=		DOCBOOK_ROOT=${PREFIX}/share/xsl/docbook/xhtml
CONFIGURE_ENV+=		XML_CATALOG=${PREFIX}/share/xml/catalog
PTHREAD_AUTO_VARS=	yes

CHECK_INTERPRETER_SKIP+=	share/sysbench/*.lua

pre-configure:
	cd ${WRKSRC} && libtoolize -f && aclocal && autoheader && \
		automake -a --foreign && autoconf

.include "options.mk"

.include "../../devel/concurrencykit/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
