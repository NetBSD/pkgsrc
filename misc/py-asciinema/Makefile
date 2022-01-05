# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:15 wiz Exp $

DISTNAME=	asciinema-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	misc multimedia python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciinema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://asciinema.org/
COMMENT=	Terminal session recorder
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=		fix-path               
SUBST_STAGE.fix-path=	pre-configure               
SUBST_MESSAGE.fix-path=	Fixing paths. 
SUBST_FILES.fix-path=	setup.py                    
SUBST_SED.fix-path=	-e 's,share/doc/asciinema,share/doc/asciinema-${PYVERSSUFFIX},g'
SUBST_SED.fix-path+=	-e 's,share/man/man1,${PKGMANDIR}/man1,g'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} asciinema asciinema-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
		${MV} asciinema.1 asciinema-${PYVERSSUFFIX}.1 || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
