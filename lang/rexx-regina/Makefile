# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:31 jmmv Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
WRKSRC=		${WRKDIR}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	implementation of the REXX language

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFLICTS=	rexx-imc-[0-9]*

.include "../../mk/bsd.pkg.mk"
