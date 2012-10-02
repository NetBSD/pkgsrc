# $NetBSD: Makefile,v 1.6 2012/10/02 21:25:18 asau Exp $
#

DISTNAME=	idzebra-2.0.47
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://ftp.indexdata.dk/pub/zebra/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.indexdata.com/zebra
COMMENT=	Structured text indexing and retrieval engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
