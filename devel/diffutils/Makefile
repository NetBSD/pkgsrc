# $NetBSD: Makefile,v 1.33 2013/05/30 16:31:33 richard Exp $
#

DISTNAME=		diffutils-3.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=diffutils/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/diffutils/diffutils.html
COMMENT=		GNU diff utilities - find the differences between files
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
INFO_FILES=		YES # PLIST

CONFIGURE_ENV+=	gt_cv_func_gnugettext1_libintl=yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	ac_cv_sys_xsi_stack_overflow_heuristic=no
.endif

AUTO_MKDIRS=		yes

post-install:
.for f in cmp diff diff3 sdiff
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor

CONFIGURE_ARGS+=	--program-prefix=g

SUBST_CLASSES+=		diff
SUBST_STAGE.diff=	pre-configure
SUBST_FILES.diff=	src/Makefile.in
SUBST_SED.diff=		-e 's;%DEFAULT_DIFF_PROGRAM%;${PREFIX}/bin/gdiff;'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
