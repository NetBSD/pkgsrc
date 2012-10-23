# $NetBSD: Makefile,v 1.9 2012/10/23 17:18:35 asau Exp $
#

DISTNAME=	libtrace-3.0.10
CATEGORIES=	net
MASTER_SITES=	http://research.wand.net.nz/software/libtrace/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://research.wand.net.nz/software/libtrace.php
COMMENT=	Library for trace processing
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake lex
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	libtrace_doxygen='false'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+=	ac_cv_have_decl_BIOCSETIF=no
CFLAGS+=	-DHAVE_VSNPRINTF
.endif

CFLAGS.Linux+=	-DHAVE_VSNPRINTF

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
