# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:45:00 jlam Exp $

DISTNAME=	pychecker-0.8.10
PKGNAME=	${PYPKGPREFIX}-checker-0.8.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pychecker/}

MAINTAINER=	shell@netbsd.org
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
