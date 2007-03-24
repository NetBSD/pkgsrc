# $NetBSD: Makefile,v 1.1.1.1 2007/03/24 14:10:31 markd Exp $
#

DISTNAME=	libtrace-3.0.0
CATEGORIES=	net
MASTER_SITES=	http://research.wand.net.nz/software/libtrace/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://research.wand.net.nz/software/libtrace.php
COMMENT=	Library for trace processing

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	libtrace_doxygen='false'

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
