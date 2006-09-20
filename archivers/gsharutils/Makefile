# $NetBSD: Makefile,v 1.42 2006/09/20 11:05:20 hira Exp $

DISTNAME=	sharutils-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	10
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives

BROKEN_GETTEXT_DETECTION=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		install install-man
INFO_FILES=		yes
USE_TOOLS+=		makeinfo msgfmt sh:run mktemp:run perl:run

REPLACE_PERL=		src/remsync.in

CONFIGURE_ARGS+=	--disable-uucode
CONFIGURE_ENV+=		SH=${TOOLS_SH:Q}

.include "../../mk/bsd.prefs.mk"

# gettext 0.11+ has renamed internal symbols, and gsharutils is
# being a very bad neighbor by using them directly.  To fix, force
# use of gettext >= 0.11, and rename the symbol in gsharutils.  -tv
#
.if ${OPSYS} != "Linux"
# XXX ...but don't do this on Linux, where glibc-internalized gettext
# always uses the non-prefixed symbols.
#
BUILDLINK_API_DEPENDS.gettext+= gettext-lib>=0.11
CPPFLAGS+=		-D_nl_default_dirname=libintl_nl_default_dirname
.endif

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

post-patch:
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/po/sharutils.pot

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
