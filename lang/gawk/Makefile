# $NetBSD: Makefile,v 1.35.2.1 2006/07/09 20:01:23 salo Exp $
#

DISTNAME=	gawk-3.1.5
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk

CONFLICTS=	ja-gawk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
TEST_TARGET=		check
INFO_FILES=		# PLIST

MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}

LDFLAGS.IRIX+=		-lgen

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gawk
PKG_SUPPORTED_OPTIONS=	portals

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mportals)
CONFIGURE_ARGS+=	--enable-portals
.endif

BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.10.36

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
