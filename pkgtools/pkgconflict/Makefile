# $NetBSD: Makefile,v 1.2 2001/04/03 18:03:03 wennmach Exp $
#

DISTNAME=	pkgconflict-0.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wennmach@netbsd.org
COMMENT=	Scripts to find conflicting packages in pkgsrc

DEPENDS+=	postgresql>=7.0:../../databases/postgresql

NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

post-extract:
	@for FILE in Makefile dewey_cmp.c pkgconflict pkgdbextract            \
	; do                                                                  \
		${SED} -e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/$$FILE          \
		    >${WRKSRC}/$$FILE;                                        \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dewey_cmp.so ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/pkgconflict ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pkgdbextract ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
