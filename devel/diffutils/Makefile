# $NetBSD: Makefile,v 1.44 2024/05/26 07:05:45 adam Exp $

DISTNAME=	diffutils-3.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=diffutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/diffutils/diffutils.html
COMMENT=	GNU diff utilities - find the differences between files
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		gmake
INFO_FILES=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes
CONFIGURE_ENV.SunOS+=	ac_cv_sys_xsi_stack_overflow_heuristic=no

SUBST_CLASSES+=		diff
SUBST_STAGE.diff=	pre-configure
SUBST_FILES.diff=	src/Makefile.in
SUBST_SED.diff=		-e 's;%DEFAULT_DIFF_PROGRAM%;${PREFIX}/bin/gdiff;'

.include "options.mk"

INSTALLATION_DIRS+=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

post-install:
.for f in cmp diff diff3 sdiff
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor

.include "../../mk/bsd.pkg.mk"
