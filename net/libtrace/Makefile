# $NetBSD: Makefile,v 1.2 2007/12/27 17:06:11 joerg Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+=	ac_cv_have_decl_BIOCSETIF=no
CFLAGS+=	-DHAVE_VSNPRINTF
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
