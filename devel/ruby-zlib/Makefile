# $NetBSD: Makefile,v 1.4 2004/11/30 17:03:15 taca Exp $
# FreeBSD: ports/archivers/ruby-zlib/Makefile,v 1.7 2000/09/26 22:01:12 knu Exp

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGPREFIX}-zlib-${RUBY_VERSION}
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		${RUBY_HOMEPAGE}
COMMENT=		Zlib library for Ruby

RUBY_VERSION_SUPPORTED=	18
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
DISTINFO_FILE=		${RUBY_DISTINFO_FILE}
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
