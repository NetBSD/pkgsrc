# $NetBSD: Makefile,v 1.4 2003/08/30 05:54:26 taca Exp $
# FreeBSD: ports/devel/ruby-amstd/Makefile,v 1.8 2000/12/06 15:38:58 knu Exp

DISTNAME=	amstd-2.0.0
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.loveruby.net/archive/amstd/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/amstd.html
COMMENT=	Collection of miscellaneous Ruby modules

DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# defined

DOCS=		README.en README.ja manual.rd.ja

do-configure:
	cd ${WRKSRC}; ${RUBY} install.rb config && ${RUBY} install.rb setup

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb install
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/amstd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
