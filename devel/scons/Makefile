# $NetBSD: Makefile,v 1.1.1.1 2004/03/09 19:13:52 recht Exp $
#

DISTNAME=		scons-0.95
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build system, written in Python

PYDISTUTILSPKG=		yes
USE_BUILDLINK3=		yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sconsign.1 ${PREFIX}/man/man1

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
