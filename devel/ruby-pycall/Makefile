# $NetBSD: Makefile,v 1.9 2024/05/26 14:52:24 taca Exp $

DISTNAME=	pycall-1.5.2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mrkn/pycall.rb
COMMENT=	Calling Python functions from Ruby
LICENSE=	mit

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	USe python command from pkgsrc
SUBST_FILES.python=	lib/pycall/libpython/finder.rb
SUBST_VARS.python=	PYTHONBIN

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
