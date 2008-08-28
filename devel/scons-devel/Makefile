# $NetBSD: Makefile,v 1.6 2008/08/28 14:42:31 tonnerre Exp $
#

DISTNAME=		scons-${SCONSVER}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scons/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scons.org/
COMMENT=		Build system, written in Python

SCONSVER=		1.0.0
PLIST_SUBST+=		SCONSVER=${SCONSVER}
INSTALLATION_DIRS=	${PKGMANDIR}/man1

PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	script/scons script/sconsign

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
