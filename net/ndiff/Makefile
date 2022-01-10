# $NetBSD: Makefile,v 1.5 2022/01/10 23:46:49 wiz Exp $

PKGREVISION= 1
.include "../../net/nmap/Makefile.common"

PKGNAME=	${DISTNAME:S/nmap/ndiff/}

COMMENT=	Compares Nmap scans

WRKSRC=		${WRKDIR}/${DISTNAME}/ndiff

EXTRACT_ELEMENTS=	${DISTNAME}/ndiff

PYTHON_VERSIONS_ACCEPTED=	27

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	pre-configure
SUBST_MESSAGE.setup=	Fixing setup.
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.setup+=	-e 's,\(self.create_uninstaller\),\#\1,g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
