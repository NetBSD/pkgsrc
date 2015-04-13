# $NetBSD: Makefile,v 1.2 2015/04/13 23:12:43 rodent Exp $

DISTNAME=	hatop-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://hatop.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://feurix.org/projects/hatop/
COMMENT=	Interactive client and monitoring tool for HAProxy
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=			bin/hatop
INSTALLATION_DIRS+=		bin ${PKGMANDIR}/man1
PY_PATCHPLIST=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

do-configure:
	# XXX: Blank, but we can't define NO_CONFIGURE and use REPLACE_PYTHON...

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hatop \
		${DESTDIR}${PREFIX}/bin/hatop${PYVERSSUFFIX}
	${INSTALL_MAN} ${WRKSRC}/man/hatop.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/hatop${PYVERSSUFFIX}.1

DEPENDS+=	haproxy>=1.4:../../net/haproxy
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
