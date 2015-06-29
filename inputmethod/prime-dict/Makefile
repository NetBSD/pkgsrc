# $NetBSD: Makefile,v 1.8 2015/06/29 11:06:47 ryoon Exp $
#

DISTNAME=	prime-dict-1.0.0
CATEGORIES=	inputmethod
MASTER_SITES=	http://prime.osdn.jp/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://taiyaki.org/prime/
COMMENT=	Japanese PRedictive Input Method Editor (dictionary)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}

RUBY_VERSION_SUPPORTED= 18

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
