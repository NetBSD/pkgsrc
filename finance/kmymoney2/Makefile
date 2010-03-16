# $NetBSD: Makefile,v 1.45 2010/03/16 09:17:38 wiz Exp $

DISTNAME=	kmymoney2-1.0.3
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmymoney2/}
EXTRACT_SUFX=  .tar.bz2

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt perl pkg-config bash
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIG_SHELL=		${BASH}
SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		gsed
USE_TOOLS+=		autoconf

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"

CONFIGURE_ARGS+=	--enable-mt

REPLACE_PERL+=	admin/fixuifiles

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.if (${OPSYS} == "NetBSD")
BUILDLINK_ABI_DEPENDS.qt3-libs+=	qt3-libs>=3.3.8nb9
.endif
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
