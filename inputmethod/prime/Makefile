# $NetBSD: Makefile,v 1.5 2010/05/16 00:26:49 obache Exp $
#

DISTNAME=	prime-1.0.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod
MASTER_SITES=	http://prime.sourceforge.jp/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://taiyaki.org/prime/
COMMENT=	Japanese PRedictive Input Method Editor
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-prime-dict>=0.8.5:../../inputmethod/prime-dict
DEPENDS+=	${RUBY_PKGPREFIX}-suikyo>=2.0:../../textproc/ruby-suikyo
DEPENDS+=	${RUBY_PKGPREFIX}-progressbar-[0-9]*:../../misc/ruby-progressbar
DEPENDS+=	${RUBY_PKGPREFIX}-sary-[0-9]*:../../textproc/ruby-sary

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	prime.pc.in

REPLACE_RUBY_DIRS=	src
REPLACE_RUBY_PAT=	*.src

CONFIGURE_ARGS+=	--with-rubydir=${PREFIX}/${RUBY_VENDORLIB}
CONFIGURE_ARGS+=	--with-prime-configdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	prime

CONF_FILES+=	${PREFIX}/share/doc/prime/examples/Custom_prime.rb \
		${PKG_SYSCONFDIR}/Custom_prime.rb

MAKE_JOBS_SAFE=	no

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
