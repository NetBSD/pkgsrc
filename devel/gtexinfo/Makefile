# $NetBSD: Makefile,v 1.71 2008/05/21 12:30:16 tnn Exp $

DISTNAME=		texinfo-4.11
PKGNAME=		g${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info documentation utilities

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
INFO_FILES=		yes
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

SUBST_CLASSES+=		macro
SUBST_STAGE.macro=	pre-configure
SUBST_MESSAGE.macro=	Replacing use of __ macro.
SUBST_FILES.macro=	makeinfo/*.c makeinfo/makeinfo.h
SUBST_SED.macro=	-e 's,\#define __(s) getdocumenttext(s),,'
SUBST_SED.macro+=	-e 's,__(",getdocumenttext(",g'

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This need to be defined here to override the setting in texinfo.mk
INSTALL_INFO=		${PREFIX}/bin/install-info
