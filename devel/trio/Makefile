# $NetBSD: Makefile,v 1.13 2017/09/06 09:03:01 wiz Exp $
#

DISTNAME=	trio-1.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ctrio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://daniel.haxx.se/projects/trio/
COMMENT=	Fully matured and stable set of printf and string functions

USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include lib

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
