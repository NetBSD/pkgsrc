# $NetBSD: Makefile,v 1.1.1.1 2002/09/02 17:22:25 agc Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	implementation of the REXX language

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}

CONFLICTS=	rexx-imc-[0-9]*

.include "../../mk/bsd.pkg.mk"
