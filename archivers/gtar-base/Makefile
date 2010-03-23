# $NetBSD: Makefile,v 1.65 2010/03/23 19:00:10 tez Exp $

DISTNAME=	tar-1.23
PKGNAME=	gtar-base-1.23
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support
LICENSE=	gnu-gpl-v3

CONFLICTS=	gcpio-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_FEATURES=		snprintf
USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} != ""
GTAR_PROGRAM_PREFIX?=	${GNU_PROGRAM_PREFIX}
.else
GTAR_PROGRAM_PREFIX?=	g
.endif

.if ${GTAR_PROGRAM_PREFIX} == ""
# pax installs a "tar" also
CONFLICTS+=		pax-[0-9]*
.else
CONFIGURE_ARGS+=	--program-prefix=${GTAR_PROGRAM_PREFIX:Q}
.endif

# lie to configure about gettext -- it does not need GNU gettext
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl=yes

PLIST_SUBST+=		GTAR_PROGRAM_PREFIX=${GTAR_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX
BUILD_DEFS+=		GTAR_PROGRAM_PREFIX
PLIST_VARS+=		gtar rmt

TEST_TARGET=		check

.if ${GTAR_PROGRAM_PREFIX} != "g"
PLIST.gtar=		yes
.endif

# don't include rmt if gtar won't build it
.if ${OPSYS} != "Interix"
PLIST.rmt=		yes
.endif

# XXX see similar hack in coreutils.
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/gtar.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${GTAR_PROGRAM_PREFIX}tar.1
.if ${GTAR_PROGRAM_PREFIX} != "g"
	${LN} -sf ${DESTDIR}${GTAR_PROGRAM_PREFIX}tar ${DESTDIR}${PREFIX}/bin/"gtar"
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
