# $NetBSD: Makefile,v 1.6 2004/12/03 15:14:54 wiz Exp $
#

DISTNAME=	c4
PKGNAME=	${DISTNAME}-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/utils/c4/

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	CVS-like frontend to Perforce

DEPENDS+=	p4-[0-9]*:../../devel/p4

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_TARGET=	c4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c4 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/c4.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
