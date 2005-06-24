# $NetBSD: Makefile,v 1.29 2005/06/24 19:12:55 kristerw Exp $

DISTNAME=	sharutils-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html
COMMENT=	Allow packing and unpacking of shell archives

BUILD_USES_MSGFMT=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALL_TARGET=		install install-man
USE_MAKEINFO=		YES
INFO_FILES=		remsync.info sharutils.info
USE_TOOLS+=		sh

CONFIGURE_ARGS+=	--disable-uucode
CONFIGURE_ENV+=		SH="${TOOLS_SH}"

.include "../../mk/bsd.prefs.mk"

.if empty(OPSYS:M*BSD)
DEPENDS+=		mktemp>=1.5:../../sysutils/mktemp
.endif

# gettext 0.11+ has renamed internal symbols, and gsharutils is
# being a very bad neighbor by using them directly.  To fix, force
# use of gettext >= 0.11, and rename the symbol in gsharutils.  -tv
#
.if ${OPSYS} != "Linux"
# XXX ...but don't do this on Linux, where glibc-internalized gettext
# always uses the non-prefixed symbols.
#
BUILDLINK_DEPENDS.gettext+= gettext-lib>=0.11
CPPFLAGS+=		-D_nl_default_dirname=libintl_nl_default_dirname
.endif

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

post-patch:
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/po/sharutils.pot

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
