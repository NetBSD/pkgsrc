# $NetBSD: Makefile,v 1.28 2024/05/29 16:33:58 adam Exp $

DISTNAME=	libtrace-4.0.10
PKGREVISION=	14
CATEGORIES=	net
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://research.wand.net.nz/software/libtrace.php
COMMENT=	Library for trace processing
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	flex gmake yacc
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	libtrace_doxygen='false'

CONFIGURE_ENV.DragonFly+=	ac_cv_have_decl_BIOCSETIF=no
CFLAGS.DragonFly+=		-DHAVE_VSNPRINTF

CFLAGS.Linux+=	-DHAVE_VSNPRINTF

FAKE_NCURSES=	yes

.include "../../misc/wandio/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
