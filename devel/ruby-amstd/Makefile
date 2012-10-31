# $NetBSD: Makefile,v 1.16 2012/10/31 11:19:40 asau Exp $

DISTNAME=	amstd-2.0.0
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/amstd/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://i.loveruby.net/en/projects/amstd/
COMMENT=	Collection of miscellaneous Ruby modules
LICENSE=	gnu-lgpl-v2.1

USE_RUBY_SETUP=		YES
USE_RUBY_SETUP_PKG=	YES
CONFIGURE_ARGS=		--site-ruby=${PREFIX}/${RUBY_VENDORLIB} \
			--so-dir=${PREFIX}/${RUBY_VENDORARCHLIB}

DOCS=			README.en README.ja manual.rd.ja

INSTALLATION_DIRS=	${RUBY_DOC}/amstd

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/amstd
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
