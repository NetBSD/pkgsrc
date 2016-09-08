# $NetBSD: Makefile,v 1.9 2016/09/08 15:19:17 joerg Exp $
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

RUBY_VERSIONS_ACCEPTED= 18

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
