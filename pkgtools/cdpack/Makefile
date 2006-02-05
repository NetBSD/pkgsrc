# $NetBSD: Makefile,v 1.22 2006/02/05 23:10:34 joerg Exp $
#

DISTNAME=	cdpack-1.7
PKGREVISION=	1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Utility to create multi-cd binary package collections

# for mkisofs
DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools

WRKSRC=		${WRKDIR}
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes

USE_TOOLS+=	awk:run
USE_TOOLS+=	expr:run
USE_TOOLS+=	sort:run
USE_TOOLS+=	tsort:run

INSTALLATION_DIRS=	bin libexec man/man1

do-build:
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@progver@;${PKGVERSION};g' \
		-e 's;@AWK@;${AWK};g' \
		-e 's;@EXPR@;${EXPR};g' \
		-e 's;@SORT@;${SORT};g' \
		-e 's;@TSORT@;${TSORT};g' \
		${FILESDIR}/cdpack.sh > \
		${WRKSRC}/cdpack
	${CHMOD} 755 ${WRKDIR}/cdpack
	${SED} -e 's;@AWK@;${AWK};g' ${FILESDIR}/cdpack.1 > \
		${WRKSRC}/cdpack.1
	${SED} -e 's;@AWK@;${AWK};g' ${FILESDIR}/cdgen.awk > \
		${WRKSRC}/cdgen.awk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cdpack ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cdgen.awk ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/cdpack.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
