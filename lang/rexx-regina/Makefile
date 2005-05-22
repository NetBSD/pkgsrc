# $NetBSD: Makefile,v 1.8 2005/05/22 20:08:11 jlam Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	Implementation of the REXX language

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFLICTS=	rexx-imc-[0-9]*

.include "../../mk/bsd.pkg.mk"
