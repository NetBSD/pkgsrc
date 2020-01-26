# $NetBSD: Makefile,v 1.7 2020/01/26 17:32:00 rillig Exp $
#

DISTNAME=	foomatic-db-4.0-20180721
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openprinting.org/download/foomatic/
COMMENT=	Printer database
LICENSE=	2-clause-bsd AND gnu-gpl-v2 AND mit

WRKSRC=		${WRKDIR}/${DISTNAME:S/-4.0//}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

# Adjust file permissions
post-extract:
	${RUN} cd ${WRKSRC}/db && \
	    ${FIND} . -type f -perm 755 -exec ${CHMOD} 644 {} \; ;

.include "../../mk/bsd.pkg.mk"
