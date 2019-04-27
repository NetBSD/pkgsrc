# $NetBSD: Makefile,v 1.15 2019/04/27 18:22:39 wiz Exp $

DISTNAME=	orc-0.4.29
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/src/orc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/orc.html
COMMENT=	Compiler for vector operations
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	orc.pc.in
PKGCONFIG_OVERRIDE+=	orc-test.pc.in

# XXX: Kludge to avoid uncoditionally pick up some gtkdoc-* tools if gtk-doc
# XXX: package is installed and then fails in the installation phase.
CONFIGURE_ENV+=		ac_cv_prog_GTKDOC_CHECK= \
			ac_cv_path_GTKDOC_CHECK_PATH= \
			ac_cv_path_GTKDOC_REBASE= \
			ac_cv_path_GTKDOC_MKPDF=

TEST_TARGET=		check


.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
