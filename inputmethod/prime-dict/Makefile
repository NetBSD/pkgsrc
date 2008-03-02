# $NetBSD: Makefile,v 1.1.1.1 2008/03/02 02:50:45 obache Exp $
#

DISTNAME=	prime-dict-1.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod
MASTER_SITES=	http://prime.sourceforge.jp/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/prime/
COMMENT=	Japanese PRedictive Input Method Editor (dictionary)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-rubydir=${RUBY_SITELIBDIR}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
