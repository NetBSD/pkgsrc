# $NetBSD: Makefile,v 1.51 2004/04/24 19:47:44 jlam Exp $

DISTNAME=		texinfo-4.6
PKGNAME=		g${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info file manipulation utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		info-stnd.info info.info texinfo
TEST_TARGET=		check
PLIST_SRC=		${PKGDIR}/PLIST

PKGSRC_INFOPATH=	${PREFIX}/info:${X11BASE}/info:${LOCALBASE}/info
MAKE_ENV+=		PKGSRC_INFOPATH="${PKGSRC_INFOPATH}"

.include "../../mk/bsd.prefs.mk"

TEXINFO_LOCALE?=	yes
BUILD_DEFS+=		TEXINFO_LOCALE
MAKEFLAGS+=		TEXINFO_LOCALE=${TEXINFO_LOCALE}
.if !empty(TEXINFO_LOCALE:M[yY][eE][sS])
USE_PKGLOCALEDIR=	yes
PLIST_SRC+=		${PKGDIR}/PLIST.locale
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
