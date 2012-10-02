# $NetBSD: Makefile,v 1.18 2012/10/02 20:11:50 asau Exp $

DISTNAME=	psyco-1.6-src
EGG_NAME=	${DISTNAME:S/-src//}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://psyco.sourceforge.net/
COMMENT=	Python JIT and execution accelerator
LICENSE=	mit

WRKSRC=		${WRKDIR}/${EGG_NAME}

PYTHON_VERSIONS_ACCEPTED=	26 25
ONLY_FOR_PLATFORM=		*-*-i386

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
