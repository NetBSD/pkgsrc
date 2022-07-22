# $NetBSD: Makefile,v 1.17 2022/07/22 17:07:13 micha Exp $

DISTNAME=	pdfpc-4.4.0
PKGREVISION=	16
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
USE_CMAKE=	yes

EGDIR=		${PREFIX}/share/examples/pdfpc
CONF_FILES+=	${EGDIR}/pdfpcrc	${PKG_SYSCONFDIR}/pdfpcrc

.include "../../devel/libgee/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
