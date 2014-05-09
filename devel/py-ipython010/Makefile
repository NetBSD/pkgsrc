# $NetBSD: Makefile,v 1.2 2014/05/09 07:37:01 wiz Exp $

DISTNAME=	ipython-0.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://archive.ipython.org/release/0.10.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.10.2 (1.0 is out)

USE_LANGUAGES=	# none
USE_TOOLS+=	gunzip

# let not to install compressed man pages.
pre-configure:
	${RUN}cd ${WRKSRC}/docs/man; gunzip *.1.gz

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
