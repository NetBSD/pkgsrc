# $NetBSD: Makefile,v 1.108 2019/10/20 16:29:42 triaxx Exp $

DISTNAME=	make-4.2.1
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
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

# XXX: Do not install gmake setgid and do not override the owner group
# XXX: based on possible /dev/kmem permissions.
CONFIGURE_ARGS+=	ac_cv_func_getloadavg_setgid=no

AUTO_MKDIRS=		yes

.include "options.mk"

post-install:
	${LN} -sf ${PREFIX}/bin/gmake ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/make
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/gmake.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/make.1

.include "../../mk/bsd.pkg.mk"
