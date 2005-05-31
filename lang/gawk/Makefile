# $NetBSD: Makefile,v 1.29 2005/05/31 10:01:37 dillo Exp $
#

DISTNAME=	gawk-3.1.4
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk

CONFLICTS=	ja-gawk-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check

INFO_FILES=	gawk.info gawkinet.info

MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gawk
PKG_SUPPORTED_OPTIONS=	portals
PKG_OPTIONS_LEGACY_VARS+=	GAWK_ENABLE_PORTALS:portals

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mportals)
CONFIGURE_ARGS+=	--enable-portals
.endif

BUILDLINK_DEPENDS.gettext+=	gettext-lib>=0.10.36

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
