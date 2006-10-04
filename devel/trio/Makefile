# $NetBSD: Makefile,v 1.8 2006/10/04 21:36:01 wiz Exp $
#

DISTNAME=	trio-1.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://daniel.haxx.se/projects/trio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://daniel.haxx.se/projects/trio/
COMMENT=	Fully matured and stable set of printf and string functions

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib man/man3

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
