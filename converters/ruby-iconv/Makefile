# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 11:21:12 taca Exp $
# FreeBSD: ports/converters/ruby-iconv/Makefile,v 1.12 2000/11/29 11:46:39 sobomax Exp

DISTNAME=	iconv-0.4.4
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://member.nifty.ne.jp/nokada/ruby.html
COMMENT=	Iconv wrapper class for Ruby

USE_BUILDLINK_ONLY= #defined

.include "../../converters/libiconv/buildlink.mk"

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
USE_RUBY_RD=	yes

INSTALL_TARGET= site-install

DOCS=		iconv.html rd.css

post-build:
	@cd ${WRKSRC}; ${RUBY_RD} iconv.c > iconv.html

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/iconv
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/iconv
.endfor

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
