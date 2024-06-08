# $NetBSD: Makefile,v 1.14 2024/06/08 11:50:56 wiz Exp $

DISTNAME=	dav1d-1.4.2
CATEGORIES=	multimedia
MASTER_SITES=	https://downloads.videolan.org/pub/videolan/dav1d/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/projects/dav1d.html
COMMENT=	AV1 decoder library
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

CPPFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		output/meson-private/dav1d.pc

INSTALLATION_DIRS+=		share/doc/${PKGBASE}

PYTHON_FOR_BUILD_ONLY=		tool

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/doc/PATENTS \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/AOM-PATENT-LICENSE

.include "../../devel/meson/build.mk"
.include "../../devel/xxhash/buildlink3.mk"
BUILDLINK_DEPMETHOD.xxhash?=	build
.include "../../mk/bsd.pkg.mk"
