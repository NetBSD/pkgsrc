# $NetBSD: Makefile,v 1.3 2003/06/02 01:18:55 jschauma Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
WRKSRC=		${WRKDIR}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	implementation of the REXX language

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFLICTS=	rexx-imc-[0-9]*

.include "../../mk/bsd.pkg.mk"
