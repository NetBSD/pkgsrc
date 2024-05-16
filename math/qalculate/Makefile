# $NetBSD: Makefile,v 1.76 2024/05/16 06:15:09 wiz Exp $

DISTNAME=	libqalculate-5.0.0
PKGNAME=	qalculate-5.0.0
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=Qalculate/}
GITHUB_PROJECT=	libqalculate
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qalculate.github.io/
COMMENT=	Modern multi-purpose desktop calculator (console version)
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf automake
USE_TOOLS+=		gmake intltool msgfmt msgmerge xgettext pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_prog_DOXYGEN=
PKGCONFIG_OVERRIDE=	libqalculate.pc.in

UNLIMIT_RESOURCES=	datasize

CFLAGS.SunOS+=		-D_LCONV_C99

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../devel/readline/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
