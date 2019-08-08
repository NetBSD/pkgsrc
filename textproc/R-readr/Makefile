# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:57 brook Exp $

R_PKGNAME=	readr
R_PKGVER=	1.3.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read rectangular text data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-clipr>=0.7.0:../../devel/R-clipr
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-hms>=0.4.1:../../time/R-hms

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
post-install:
	install_name_tool \
		-change \
		@loader_path/../rcon/librcon.so \
		${PREFIX}/lib/R/library/readr/rcon/librcon.so \
		${DESTDIR}${PREFIX}/lib/R/library/readr/libs/readr.so
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
