# $NetBSD: Makefile,v 1.9 2006/10/31 23:13:51 joerg Exp $
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
