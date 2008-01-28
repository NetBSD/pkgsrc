# $NetBSD: Makefile,v 1.26 2008/01/28 23:06:13 dmcmahill Exp $
#

DISTNAME=	cdpack-1.8
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Utility to create multi-cd/dvd binary package collections

# for mkisofs
DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

USE_TOOLS+=	awk:run
USE_TOOLS+=	expr:run
USE_TOOLS+=	printf:run
USE_TOOLS+=	sort:run
USE_TOOLS+=	tsort:run

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1

do-build:
.for f in cdpack cddist
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@progver@;${PKGVERSION};g' \
		-e 's;@AWK@;${AWK};g' \
		-e 's;@EXPR@;${EXPR};g' \
		-e 's;@PRINTF@;${PRINTF};g' \
		-e 's;@SORT@;${SORT};g' \
		-e 's;@TSORT@;${TSORT};g' \
		${FILESDIR}/${f}.sh > \
		${WRKSRC}/${f}
	${CHMOD} 755 ${WRKDIR}/${f}
	${SED} -e 's;@AWK@;${AWK};g' ${FILESDIR}/${f}.1 > \
		${WRKSRC}/${f}.1
.endfor
	${SED} -e 's;@AWK@;${AWK};g' ${FILESDIR}/cdgen.awk > \
		${WRKSRC}/cdgen.awk

do-install:
.for f in cdpack cddist
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${PREFIX}/${PKGMANDIR}/man1
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/cdgen.awk ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
