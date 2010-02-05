# $NetBSD: Makefile,v 1.48 2010/02/05 08:44:03 obache Exp $

DISTNAME=	gettext-0.14.6
PKGNAME=	gettext-lib-0.14.6
SVR4_PKGNAME=	gttli
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gettext/gettext.html
COMMENT=	Internationalized Message Handling Library (libintl)

CONFLICTS=		gettext<=0.10.35

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-included-gettext
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}

CFLAGS+=		${CFLAGS.${ICONV_TYPE}-iconv}
CFLAGS.gnu-iconv+=	-DHAVE_GNU_ICONV

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} localedir=${EGDIR}

CONFIGURE_DIRS=		gettext-runtime
BUILD_DIRS=		gettext-runtime/intl
EGDIR=			${PREFIX}/share/examples/gettext
LOCALEDIR=		${PREFIX}/${PKGLOCALEDIR}/locale

REQD_DIRS+=		${LOCALEDIR}
REQD_FILES+=		${EGDIR}/locale.alias ${LOCALEDIR}/locale.alias

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
