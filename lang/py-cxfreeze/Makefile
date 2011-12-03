# $NetBSD: Makefile,v 1.3 2011/12/03 00:02:15 joerg Exp $
#

VERS=			4.2.2
DISTNAME=		cx_Freeze-${VERS}
PKGNAME=		${PYPKGPREFIX}-cxfreeze-${VERS}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cx-freeze/}

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://cx-freeze.sourceforge.net/
COMMENT=		Freezing python scripts into executables
LICENSE=		python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=      	c c++

PYDISTUTILSPKG=         yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/cxfreeze ${WRKSRC}/cxfreeze${PYVERSSUFFIX}

# XXX this pkg abuses the distutils extension build mechanism to
# build executables. The result isn't executable on NetBSD.
# Relink to get valid executables.
post-build:
	cd ${WRKSRC} && ${CC} build/temp.*/source/bases/Console.o \
	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lpython${PYVERSSUFFIX} \
	-o ${WRKDIR}/Console && \
	${CC} build/temp.*/source/bases/ConsoleKeepPath.o \
	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lpython${PYVERSSUFFIX} \
	-o ${WRKDIR}/ConsoleKeepPath

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/Console \
		${DESTDIR}${PREFIX}/${PYSITELIB}/cx_Freeze/bases
	${INSTALL_PROGRAM} ${WRKDIR}/ConsoleKeepPath \
		${DESTDIR}${PREFIX}/${PYSITELIB}/cx_Freeze/bases

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
