# $NetBSD: Makefile,v 1.2 2021/06/10 06:02:14 nia Exp $

DISTNAME=	ocl-icd-2.3.0
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCL-dev/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OCL-dev/ocl-icd
COMMENT=	OpenCL ICD Loader
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	autoconf autoreconf automake
USE_TOOLS+=	gmake

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../lang/ruby/rubyversion.mk"

TOOL_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

PKGCONFIG_OVERRIDE+=	OpenCL.pc.in
PKGCONFIG_OVERRIDE+=	ocl-icd.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../parallel/opencl-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
