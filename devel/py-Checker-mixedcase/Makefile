# $NetBSD: Makefile,v 1.1.1.1 2002/01/29 16:27:53 drochner Exp $

DISTNAME=	pychecker-0.8.8
PKGNAME=	${PYPKGPREFIX}-checker-0.8.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://pychecker.sourceforge.net/
COMMENT=	python code checker

PYDISTUTILSPKG=	# defined
PYSETUP=	setup.py.new
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-patch:
	@${SED} -e "s|@PREFIX@|${PREFIX}|" \
		-e "s|@PYPKGPREFIX@|${PYPKGPREFIX}|" \
		<${WRKSRC}/setup.py  > ${WRKSRC}/setup.py.new

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
