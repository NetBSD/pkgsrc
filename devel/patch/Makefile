# $NetBSD: Makefile,v 1.44.6.1 2018/10/20 16:12:15 spz Exp $

DISTNAME=	patch-2.7.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=patch/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/patch/patch.html
COMMENT=	Patch files using diff output
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		awk

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--program-prefix=g
CONFIGURE_ENV+=		ac_cv_func_setmode_dos=no	# Fix for Interix (and old bsd?)

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

SYMLINKS=	bin/gpatch ${PKGGNUDIR}bin/patch \
		man/man1/gpatch.1 ${PKGGNUDIR}${PKGMANDIR}/man1/patch.1
post-install:
.for o n in ${SYMLINKS}
	${LN} -sf ${PREFIX}/${o} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../mk/bsd.pkg.mk"
