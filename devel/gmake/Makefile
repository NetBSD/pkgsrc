# $NetBSD: Makefile,v 1.20 1999/12/21 19:50:01 tron Exp $
# FreeBSD Id: Makefile,v 1.16 1997/06/13 20:00:47 max Exp
#

DISTNAME=       make-3.78.1
PKGNAME=        gmake-3.78.1
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:=make/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/make/make.html

CONFIGURE_ARGS=	--program-prefix="g"
GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

post-extract:
	${MV} ${WRKSRC}/make.texinfo ${WRKSRC}/make.texinfo.orig
	${SED} '/@dircategory/s|.*|@dircategory Programming \& development tools|' \
	    < ${WRKSRC}/make.texinfo.orig > ${WRKSRC}/make.texinfo

post-install:
	${CHMOD} g-s ${PREFIX}/bin/gmake
	${CHGRP} ${BINGRP} ${PREFIX}/bin/gmake

.include "../../mk/bsd.pkg.mk"
