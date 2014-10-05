# $NetBSD: Makefile,v 1.2 2014/10/05 16:27:25 wiz Exp $

DISTNAME=	lockf-1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.FreeBSD.org/
COMMENT=	FreeBSD's lockf
LICENSE=	original-bsd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c

do-extract:
	cd ${FILESDIR} && cp *.c *.1 ${WRKSRC}/

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}; \
	 ${ECHO} "${CC} -o lockf lockf.c"; \
	 ${CC} -o lockf lockf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lockf ${DESTDIR}${PREFIX}/bin/lockf
	${INSTALL_MAN} ${WRKSRC}/lockf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
