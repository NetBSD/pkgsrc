# $NetBSD: Makefile,v 1.9 2006/10/22 06:39:43 rillig Exp $
#

DISTNAME=		scons-0.96.1
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build system, written in Python

PYDISTUTILSPKG=		yes
INSTALLATION_DIRS=	${PKGMANDIR}/man1

# XXX The dependency on py-xml below is not needed for
# standard operation. There is an extension to scons (bksys)
# however which needs XML processing. Putting a dependency
# on px-xml-for-the-python-version-used-by-scons elsewhere
# would be too complicated.

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/sconsign.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
# XXX see comment above
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
