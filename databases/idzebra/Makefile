# $NetBSD: Makefile,v 1.49 2023/12/30 01:59:54 zafer Exp $
#

DISTNAME=	idzebra-2.0.62
PKGREVISION=	24
CATEGORIES=	databases
MASTER_SITES=	https://download.indexdata.com/pub/zebra/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.indexdata.com/zebra
COMMENT=	Structured text indexing and retrieval engine
LICENSE=	gnu-gpl-v2
REPLACE_PERL=	util/idzebra-abs2dom

USE_TOOLS=	perl:run
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

CPPFLAGS+=	-DUSE_INTERP_RESULT -DUSE_INTERP_ERRORLINE

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
