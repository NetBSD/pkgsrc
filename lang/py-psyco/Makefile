# $NetBSD: Makefile,v 1.19 2012/10/03 22:14:02 wiz Exp $

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

PYTHON_VERSIONS_ACCEPTED=	26
ONLY_FOR_PLATFORM=		*-*-i386

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
