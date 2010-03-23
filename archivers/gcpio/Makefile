# $NetBSD: Makefile,v 1.38 2010/03/23 22:42:17 tez Exp $
#

DISTNAME=	cpio-2.6
PKGNAME=	g${DISTNAME}
PKGREVISION=	6
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support
LICENSE=	gnu-gpl-v2

CONFLICTS+=	gtar-base-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

TEST_TARGET=	check

CONFIGURE_ENV+=	gt_cv_func_gnugettext1_libintl=yes

.include "../../mk/bsd.prefs.mk"

LIBS.NetBSD+=	-lgnumalloc

.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} == ""
# pax installs a "cpio" also
CONFLICTS+=	pax-[0-9]*
.endif

BUILD_DEFS+=		GNU_PROGRAM_PREFIX
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
