# $NetBSD: Makefile,v 1.11 2012/10/31 11:19:51 asau Exp $
#

DISTNAME=	trio-1.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctrio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://daniel.haxx.se/projects/trio/
COMMENT=	Fully matured and stable set of printf and string functions

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
