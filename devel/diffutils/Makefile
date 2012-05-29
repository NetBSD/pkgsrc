# $NetBSD: Makefile,v 1.27 2012/05/29 21:01:25 cheusov Exp $
#

DISTNAME=		diffutils-3.2
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=diffutils/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/diffutils/diffutils.html
COMMENT=		GNU diff utilities - find the differences between files
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
INFO_FILES=		YES # PLIST

CONFIGURE_ENV+=	gt_cv_func_gnugettext1_libintl=yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_sys_xsi_stack_overflow_heuristic=no
.endif

PROGS=	cmp diff diff3 sdiff

INSTALLATION_DIRS+=	gnu/bin

post-install:
	set -e; \
	cd ${DESTDIR}${PREFIX}/gnu/bin; \
	for p in ${PROGS}; do \
	   ln -f -s "../../bin/g$${p}" "$${p}"; \
	done

CONFIGURE_ARGS+=	--program-prefix=g

SUBST_CLASSES+=		diff
SUBST_STAGE.diff=	pre-configure
SUBST_FILES.diff=	src/Makefile.in
SUBST_SED.diff=		-e 's;%DEFAULT_DIFF_PROGRAM%;${PREFIX}/bin/gdiff;'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
