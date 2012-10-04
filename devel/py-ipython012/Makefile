# $NetBSD: Makefile,v 1.5 2012/10/04 00:21:58 cheusov Exp $
#

DISTNAME=	ipython-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://archive.ipython.org/release/0.12/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://ipython.org/
COMMENT=	Interactive computing environment for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect

PKG_DESTDIR_SUPPORT=	user-destdir
PYTHON_SELF_CONFLICT=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	gunzip

# let not to install compressed man pages.
pre-configure:
	${RUN}cd ${WRKSRC}/docs/man; gunzip *.1.gz

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
