# $NetBSD: Makefile,v 1.7 2004/03/16 02:01:09 taca Exp $
#

DISTNAME=	iconv-0.5
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	converters ruby
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://member.nifty.ne.jp/nokada/ruby.html
COMMENT=	Iconv wrapper class for Ruby

USE_BUILDLINK2= # defined

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
USE_RUBY_RD=	yes

INSTALL_TARGET= site-install

DOCS=		iconv.html rd.css

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/iconv
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/iconv
.endfor

.include "../../converters/libiconv/buildlink2.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
