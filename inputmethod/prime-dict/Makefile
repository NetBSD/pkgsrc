# $NetBSD: Makefile,v 1.4 2010/09/10 06:58:06 taca Exp $
#

DISTNAME=	prime-dict-1.0.0
CATEGORIES=	inputmethod
MASTER_SITES=	http://prime.sourceforge.jp/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/prime/
COMMENT=	Japanese PRedictive Input Method Editor (dictionary)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
