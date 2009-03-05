# $NetBSD: Makefile,v 1.15 2009/03/05 18:51:29 joerg Exp $

DISTNAME=	psyco-1.6-src
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-src//}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psyco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://psyco.sourceforge.net/
COMMENT=	Python JIT and execution accelerator

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

ONLY_FOR_PLATFORM=		*-*-i386

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
