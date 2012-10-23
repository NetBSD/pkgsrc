# $NetBSD: Makefile,v 1.5 2012/10/23 18:17:00 asau Exp $

DISTNAME=	hairyeyeball-1.1
PKGREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	http://www.blafasel.org/~floh/he/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blafasel.org/~floh/he/
COMMENT=	Systrace policy examples

WRKSRC=		${WRKDIR}/1.1

NO_BUILD=	YES

INSTALLATION_DIRS+=	share/examples/systrace-policies

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/share/examples/systrace-policies

.include "../../mk/bsd.pkg.mk"
