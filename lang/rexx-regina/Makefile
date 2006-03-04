# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:56 jlam Exp $
#

DISTNAME=	regina301
PKGNAME=	rexx-regina-3.0.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=regina-rexx/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://regina-rexx.sourceforge.net/
COMMENT=	Implementation of the REXX language

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFLICTS=	rexx-imc-[0-9]*

.include "../../mk/bsd.pkg.mk"
