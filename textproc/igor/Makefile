# $NetBSD: Makefile,v 1.6 2019/08/11 13:23:24 wiz Exp $

DISTNAME=	igor
PKGNAME=	igor-0.0.20140517
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://www.wonkity.com/~wblock/igor/
DISTFILES=	igor igor.pdf readme.txt
EXTRACT_SUFX=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wonkity.com/~wblock/igor/
COMMENT=	FreeBSD Project documentation sanity checker
LICENSE=	2-clause-bsd

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
REPLACE_PERL=	igor

INSTALLATION_DIRS=	bin share/doc/igor

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igor ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/igor.pdf ${DESTDIR}${PREFIX}/share/doc/igor
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DESTDIR}${PREFIX}/share/doc/igor

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
