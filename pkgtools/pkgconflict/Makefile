# $NetBSD: Makefile,v 1.13 2005/01/05 21:15:15 tv Exp $
#

DISTNAME=	pkgconflict-0.4
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wennmach@NetBSD.org
COMMENT=	Scripts to find conflicting packages in pkgsrc

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
PKG_INSTALLATION_TYPES= overwrite pkgviews
USE_BUILDLINK3=	yes

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql/server

post-extract:
	@for f in dewey_cmp.c pkgconflict pkgdbextract; do \
		${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/$$f >${WRKSRC}/$$f; \
	done

do-build:
	cd ${WRKSRC} && ${COMPILE.c} -fPIC dewey_cmp.c
	cd ${WRKSRC} && ${LINK.c} -shared -o dewey_cmp.so dewey_cmp.o

do-install:
	${INSTALL_LIB} ${WRKSRC}/dewey_cmp.so ${PREFIX}/lib/postgresql/
	${INSTALL_SCRIPT} ${WRKSRC}/pkgconflict ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdbextract ${PREFIX}/bin/

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
