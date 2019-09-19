# $NetBSD: Makefile,v 1.1 2019/09/19 23:53:36 rillig Exp $

DISTNAME=	check-perms-1.0
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Ensures that wrong file permissions are fixed
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}
BUILD_DIRS=	# none
AUTO_MKDIRS=	yes

USE_TOOLS+=	pax

do-extract:
	cd ${WRKSRC} && > demo-file && chmod 777 demo-file

do-install:
	cd ${WRKSRC} && pax -wr -pp demo-file ${DESTDIR}${PREFIX}/share/regress-check-perms/

.include "../../mk/bsd.pkg.mk"
