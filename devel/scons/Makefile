# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:05 wiz Exp $
#

DISTNAME=		scons-0.96.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build system, written in Python

PYDISTUTILSPKG=		yes

# XXX The dependency on py-xml below is not needed for
# standard operation. There is an extension to scons (bksys)
# however which needs XML processing. Putting a dependency
# on px-xml-for-the-python-version-used-by-scons elsewhere
# would be too complicated.

post-install:
	${INSTALL_MAN} ${WRKSRC}/scons.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sconsign.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
# XXX see comment above
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
