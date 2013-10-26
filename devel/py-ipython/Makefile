# $NetBSD: Makefile,v 1.5 2013/10/26 12:15:59 obache Exp $
#

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

USE_LANGUAGES=	# none
USE_TOOLS+=	gunzip

# let not to install compressed man pages.
pre-configure:
	${RUN}cd ${WRKSRC}/docs/man; gunzip *.1.gz

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
