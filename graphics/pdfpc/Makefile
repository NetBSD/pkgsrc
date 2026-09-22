# $NetBSD: Makefile,v 1.55 2026/09/22 03:52:36 ryoon Exp $

DISTNAME=	pdfpc-4.7.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=pdfpc/}
GITHUB_PROJECT=	pdfpc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pdfpc.github.io/
COMMENT=	Presenter console with multi-monitor support for PDF files
LICENSE=	gnu-gpl-v2

DEPENDS+=	gst-plugins1-gtk-[0-9]*:../../multimedia/gst-plugins1-gtk

USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DMDVIEW=OFF # requires webkit-gtk
CMAKE_CONFIGURE_ARGS+=	-DREST=OFF # disable remote comtrol via REST

EGDIR=		${PREFIX}/share/examples/pdfpc
CONF_FILES+=	${EGDIR}/pdfpcrc	${PKG_SYSCONFDIR}/pdfpcrc

.include "../../devel/cmake/build.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
