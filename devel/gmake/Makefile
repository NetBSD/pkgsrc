# $NetBSD: Makefile,v 1.29.2.1 2002/05/11 02:09:03 jlam Exp $
# FreeBSD Id: Makefile,v 1.16 1997/06/13 20:00:47 max Exp
#

DISTNAME=       make-3.79.1
PKGNAME=        gmake-3.79.1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=make/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility

USE_BUILDLINK2_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix="g"
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
TEXINFO_OVERRIDE=	YES

post-extract:
	${MV} ${WRKSRC}/make.texinfo ${WRKSRC}/make.texinfo.orig
	${SED} '/@dircategory/s|.*|@dircategory Programming \& development tools|' \
	    < ${WRKSRC}/make.texinfo.orig > ${WRKSRC}/make.texinfo

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	${CHGRP} ${BINGRP} ${PREFIX}/bin/gmake

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
