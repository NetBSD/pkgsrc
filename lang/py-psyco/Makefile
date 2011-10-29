# $NetBSD: Makefile,v 1.16 2011/10/29 04:26:12 obache Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${EGG_NAME}

ONLY_FOR_PLATFORM=		*-*-i386

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
