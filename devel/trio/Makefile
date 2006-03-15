# $NetBSD: Makefile,v 1.7 2006/03/15 16:44:50 joerg Exp $
#

DISTNAME=	trio-1.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.contactor.se/~dast/stuff/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.contactor.se/~dast/trio/
COMMENT=	Fully matured and stable set of printf and string functions

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib man/man3

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
