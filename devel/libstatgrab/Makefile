# $NetBSD: Makefile,v 1.39 2022/06/28 11:31:47 wiz Exp $

DISTNAME=	libstatgrab-0.92
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libstatgrab/}
GITHUB_PROJECT=	libstatgrab
GITHUB_RELEASE=	LIBSTATGRAB_${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libstatgrab.org/
COMMENT=	Provides a useful interface to system statistics
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

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

.include "options.mk"
.include "../../devel/log4cplus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
