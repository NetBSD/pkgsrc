# $NetBSD: Makefile,v 1.1.1.1 2001/04/02 18:04:03 wennmach Exp $
#

DISTNAME=	pkgconflict-0.1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wennmach@netbsd.org
COMMENT=	Script to find conflicting packages in pkgsrc

DEPENDS+=	postgresql>=7.0:../../databases/postgresql

NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

post-extract:
	@for FILE in Makefile dewey_cmp.c pkgconflict                         \
	; do                                                                  \
		${SED} -e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/$$FILE          \
		    >${WRKSRC}/$$FILE;                                        \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dewey_cmp.so ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/pkgconflict ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
