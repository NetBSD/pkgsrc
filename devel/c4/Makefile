# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:30 jmmv Exp $
#

DISTNAME=	c4
PKGNAME=	${DISTNAME}-1.6
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/utils/c4/

MAINTAINER=	schmonz@netbsd.org
COMMENT=	CVS-like frontend to Perforce

DEPENDS+=	p4-[0-9]*:../../devel/p4

ALL_TARGET=	c4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c4 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/c4.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
