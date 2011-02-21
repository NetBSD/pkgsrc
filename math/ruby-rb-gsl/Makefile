# $NetBSD: Makefile,v 1.9 2011/02/21 16:01:18 taca Exp $

DISTNAME=	rb-gsl-1.14.5
PKGREVISION=	1
CATEGORIES=	math ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/73285/
EXTRACT_SUFX=	.tgz


MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rb-gsl.rubyforge.org/
COMMENT=	Ruby interface to the GNU Scientific Library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_RUBY_SETUP=	yes
USE_TOOLS=	pax
CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

REPLACE_RUBY_DIRS=	examples

INSTALLATION_DIRS=	${RUBY_DOC}/gsl ${RUBY_EG}/gsl

.include "../../lang/ruby/modules.mk"
.include "../../math/gsl/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${RUBY_DOC}/gsl
	cd ${WRKSRC}/examples; pax -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}/gsl

.include "../../mk/bsd.pkg.mk"
