# $NetBSD: Makefile,v 1.52 2019/07/07 08:54:30 bsiegert Exp $

DISTNAME=	cpio-2.12
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=cpio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cpio/cpio.html
COMMENT=	GNU copy-in/out (cpio) with remote magnetic tape (rmt) support
LICENSE=	gnu-gpl-v3

CONFLICTS+=	gtar-base-[0-9]*

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

AUTO_MKDIRS=	yes

TEST_TARGET=		check

CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl=yes
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes

CONFIGURE_ARGS+=	--program-prefix=g

PLIST_VARS+=	rmt

.include "../../mk/bsd.prefs.mk"

# don't include rmt if gtar won't build it
# macOS does not support rmt driver, so it won't be built
.if ${OPSYS} != "Interix" && ${OPSYS} != "Darwin"
PLIST.rmt=	yes
.endif


post-install:
	${LN} -sf ${PREFIX}/bin/gcpio ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/cpio
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gcpio.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/cpio.1
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gmt.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/mt.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
