# $NetBSD: Makefile,v 1.8 2005/03/24 21:12:53 wiz Exp $

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-zlib-${RUBY_VERSION}
PKGREVISION=		1
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Zlib library for Ruby

RUBY_HAS_ARCHLIB=	yes
RUBY_VERSION_SUPPORTED=	18
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/zlib
WRKSRC=			${RUBY_WRKSRC}/ext/zlib

INSTALL_TARGET=		site-install
DOCS=			doc/zlib.rd

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/zlib
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/zlib
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
