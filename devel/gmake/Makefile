# $NetBSD: Makefile,v 1.40 2002/12/02 02:14:33 salo Exp $

DISTNAME=       make-3.80
PKGNAME=        gmake-3.80
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=make/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
CONFIGURE_ARGS+=	--program-prefix="g"
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}
TEXINFO_OVERRIDE=	YES
TEXINFO_REQD=		4.0

post-extract:
	${MV} ${WRKSRC}/doc/make.texi ${WRKSRC}/doc/make.texi.orig
	${SED} '/@dircategory/s|.*|@dircategory Programming \& development tools|' \
	    < ${WRKSRC}/doc/make.texi.orig > ${WRKSRC}/doc/make.texi

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	${CHGRP} ${BINGRP} ${PREFIX}/bin/gmake

# NOTE:  the 'test' target requires perl, but since gmake does
# not otherwise require it, perl is not listed as an explicit
# dependency
test: build
	cd ${WRKSRC} && \
		${MAKE_ENV} ${MAKE_PROGRAM} check 2>&1 | \
		tee ${WRKDIR}/tests.log

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
