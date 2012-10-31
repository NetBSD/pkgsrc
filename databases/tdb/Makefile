# $NetBSD: Makefile,v 1.18 2012/10/31 13:09:48 wiz Exp $
#

DISTNAME=	tdb-1.2.10
CATEGORIES=	databases
MASTER_SITES=	http://www.samba.org/ftp/tdb/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

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

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
