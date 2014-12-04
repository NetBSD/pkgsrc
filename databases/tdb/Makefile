# $NetBSD: Makefile,v 1.24 2014/12/04 11:13:25 mef Exp $

DISTNAME=	tdb-1.3.3
CATEGORIES=	databases
MASTER_SITES=	http://www.samba.org/ftp/tdb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

# both install tdbtool and tdbdump
CONFLICTS+=	samba<3.6.6nb3

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE=	tdb.pc.in

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON+= buildtools/bin/waf
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.2.12

USE_GCC_RUNTIME=	yes

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
