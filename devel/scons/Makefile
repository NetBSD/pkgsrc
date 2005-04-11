# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:38 tv Exp $
#

DISTNAME=		scons-0.96.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build system, written in Python

PYDISTUTILSPKG=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sconsign.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
