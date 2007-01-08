# $NetBSD: Makefile,v 1.66.2.1 2007/01/08 12:01:21 ghen Exp $

DISTNAME=		texinfo-4.8
PKGNAME=		g${DISTNAME}
PKGREVISION=		7
CATEGORIES=		devel sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info documentation utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST
TEST_TARGET=		check
PLIST_SRC=		${PKGDIR}/PLIST

PKGSRC_INFOPATH=	${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
MAKE_ENV+=		PKGSRC_INFOPATH=${PKGSRC_INFOPATH:Q}

.include "../../mk/bsd.prefs.mk"

TEXINFO_LOCALE?=	yes
BUILD_DEFS+=		TEXINFO_LOCALE
MAKEFLAGS+=		TEXINFO_LOCALE=${TEXINFO_LOCALE:Q}
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
