# $NetBSD: Makefile,v 1.1.1.1 2003/06/27 14:16:34 drochner Exp $
#

DISTNAME=		pychecker-0.8.12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://belnet.dl.sourceforge.net/sourceforge/pychecker/
COMMENT=		tool for finding bugs in python source code

USE_BUILDLINK2=		yes
PYDISTUTILSPKG=	yes
PLIST_SUBST+= PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
