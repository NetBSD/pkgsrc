# $NetBSD: Makefile,v 1.2 2005/01/28 14:08:01 taca Exp $
#

DISTNAME=	iconv-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	converters ruby
MASTER_SITES=	http://nokada.jin.gr.jp/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Iconv wrapper class for Ruby

RUBY_VERSION=		${RUBY16_VERSION}
RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		YES
USE_RUBY_EXTCONF=	YES
USE_RUBY_RD=		YES

DOCS=			iconv.html rd.css

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/iconv
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/iconv
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
