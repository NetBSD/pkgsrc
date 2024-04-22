# $NetBSD: Makefile,v 1.6 2024/04/22 10:43:29 adam Exp $

DISTNAME=	ocl-icd-2.3.2
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCL-dev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OCL-dev/ocl-icd
COMMENT=	OpenCL ICD Loader
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf autoreconf automake gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../lang/ruby/rubyversion.mk"

MAKE_FLAGS+=	RUBY=${RUBY:Q}

TOOL_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

CONFIGURE_ARGS+=	--enable-custom-vendordir=${PKG_SYSCONFDIR}/OpenCL/vendors

PKGCONFIG_OVERRIDE+=	OpenCL.pc.in
PKGCONFIG_OVERRIDE+=	ocl-icd.pc.in

MAKE_FLAGS.SunOS+=	USE_MAP_TRUE='#'
MAKE_FLAGS.SunOS+=	USE_MAP_FALSE=

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../parallel/opencl-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
