# $NetBSD: Makefile,v 1.4 2003/07/17 21:45:18 grant Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
WRKSRC=		${WRKDIR}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	implementation of the REXX language

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFLICTS=	rexx-imc-[0-9]*

.include "../../mk/bsd.pkg.mk"
