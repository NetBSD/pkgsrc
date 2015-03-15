# $NetBSD: Makefile,v 1.7 2015/03/15 19:42:33 hiramatsu Exp $
#

DISTNAME=	prime-dict-1.0.0
CATEGORIES=	inputmethod
MASTER_SITES=	http://prime.sourceforge.jp/src/

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
