# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:17 tv Exp $
#

DISTNAME=	iconv-0.5
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters ruby
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://member.nifty.ne.jp/nokada/ruby.html
COMMENT=	Iconv wrapper class for Ruby

USE_BUILDLINK3= # defined

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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
