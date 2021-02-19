# $NetBSD: Makefile,v 1.1 2021/02/19 18:01:39 nros Exp $

DISTNAME=	dav1d-0.8.1
CATEGORIES=	multimedia
MASTER_SITES=	https://downloads.videolan.org/pub/videolan/dav1d/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/projects/dav1d.html
COMMENT=	AV1 decoder library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		output/meson-private/dav1d.pc

INSTALLATION_DIRS+=		share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSE
	${INSTALL_DATA} ${WRKSRC}/doc/PATENTS \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/AOM-PATENT-LICENSE

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
