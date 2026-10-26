# $NetBSD: Makefile,v 1.48 2026/10/26 16:47:06 wiz Exp $

DISTNAME=	patch-2.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=patch/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/patch/patch.html
COMMENT=	Apply changes to files using diff output
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		awk
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--program-prefix=g

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

SYMLINKS=	bin/gpatch ${PKGGNUDIR}bin/patch \
		man/man1/gpatch.1 ${PKGGNUDIR}${PKGMANDIR}/man1/patch.1
post-install:
.for o n in ${SYMLINKS}
	${LN} -sf ${PREFIX}/${o} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../mk/bsd.pkg.mk"
