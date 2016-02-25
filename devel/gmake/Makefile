# $NetBSD: Makefile,v 1.93 2016/02/25 12:12:48 jperkin Exp $

DISTNAME=	make-4.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=make/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility
LICENSE=	gnu-gpl-v3

USE_FEATURES=		snprintf

GNU_CONFIGURE=		yes
TEXINFO_REQD+=		4.0
INFO_FILES=		yes

# NOTE:  the 'test' target requires perl, but since gmake does
# not otherwise require it, perl is not listed as an explicit
# dependency
TEST_TARGET=		check

CONFIGURE_ARGS+=	--program-prefix=g

# workaround for broken strndup
CONFIGURE_ARGS.MirBSD+=	ac_cv_func_strndup=no

AUTO_MKDIRS=		yes

PLIST_SRC=		${PKGDIR}/PLIST

.include "options.mk"

post-install:
	${CHMOD} g-s ${DESTDIR}${PREFIX}/bin/gmake
	${CHGRP} ${BINGRP} ${DESTDIR}${PREFIX}/bin/gmake
	${LN} -sf ${PREFIX}/bin/gmake ${DESTDIR}${PREFIX}/${PKGGNUDIR}/bin/make
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gmake.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/make.1

.include "../../mk/bsd.pkg.mk"
