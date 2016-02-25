# $NetBSD: Makefile,v 1.12 2016/02/25 16:20:51 jperkin Exp $
#

DISTNAME=	libtrace-3.0.10
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://research.wand.net.nz/software/libtrace/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://research.wand.net.nz/software/libtrace.php
COMMENT=	Library for trace processing
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake lex yacc
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	libtrace_doxygen='false'

CONFIGURE_ENV.DragonFly+=	ac_cv_have_decl_BIOCSETIF=no
CFLAGS.DragonFly+=		-DHAVE_VSNPRINTF

CFLAGS.Linux+=	-DHAVE_VSNPRINTF

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
