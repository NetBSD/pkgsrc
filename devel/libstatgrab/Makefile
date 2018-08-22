# $NetBSD: Makefile,v 1.34 2018/08/22 09:43:33 wiz Exp $

DISTNAME=	libstatgrab-0.91
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/libstatgrab/
MASTER_SITES+=	ftp://ftp.i-scream.org/pub/i-scream/libstatgrab/
MASTER_SITES+=	http://ftp.i-scream.org/pub/i-scream/libstatgrab/
MASTER_SITES+=	http://www.mirrorservice.org/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/
MASTER_SITES+=	http://dl.ambiweb.de/mirrors/ftp.i-scream.org/libstatgrab/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.i-scream.org/libstatgrab/
COMMENT=	Provides a useful interface to system statistics
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

.include "options.mk"

CPPFLAGS.NetBSD+=	-D_KERNTYPES

USE_TOOLS+=		pkg-config perl:run
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libstatgrab.pc.in

REPLACE_PERL+=		src/statgrab/statgrab-make-mrtg-config.in
REPLACE_PERL+=		src/statgrab/statgrab-make-mrtg-index.in

CONFIGURE_ARGS+=	--disable-examples

# Default test target for Perl modules
TEST_TARGET?=		test

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no

.include "../../devel/log4cplus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
