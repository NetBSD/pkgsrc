# $NetBSD: Makefile,v 1.29.8.1 2002/08/20 12:49:43 agc Exp $
# FreeBSD Id: Makefile,v 1.16 1997/06/13 20:00:47 max Exp
#

DISTNAME=       make-3.79.1
PKGNAME=        gmake-3.79.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=make/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html
COMMENT=	GNU version of 'make' utility

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix="g"
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
TEXINFO_OVERRIDE=	YES

.include "../../mk/bsd.prefs.mk"

.if (${GMAKE_NSEC_TIMESTAMPS} == "NO")
CONFIGURE_ARGS+=	--disable-nsec-timestamps
.endif

BUILD_DEFS+=	GMAKE_NSEC_TIMESTAMPS

post-extract:
	${MV} ${WRKSRC}/make.texinfo ${WRKSRC}/make.texinfo.orig
	${SED} '/@dircategory/s|.*|@dircategory Programming \& development tools|' \
	    < ${WRKSRC}/make.texinfo.orig > ${WRKSRC}/make.texinfo

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	${CHGRP} ${BINGRP} ${PREFIX}/bin/gmake

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
