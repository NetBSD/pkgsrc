# $NetBSD: Makefile,v 1.3 2002/01/03 16:10:01 taca Exp $
# FreeBSD: ports/sysutils/ruby-syslog/Makefile,v 1.4 2000/09/26 08:02:09 knu Exp

DISTNAME=	syslog-20010130
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.utdallas.edu/pub/staff/amos/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.utdallas.edu/~amos/ruby.html
COMMENT=	Ruby module to access syslog(3) interface

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
CONFLICTS=	ruby>=1.6.6

RUBY_VER=	1.4		# now this is for ruby 1.4 only.

INSTALL_TARGET=	site-install

pre-configure:
	rm ${WRKSRC}/depend

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/syslog
	${INSTALL_DATA} ${WRKSRC}/0README ${RUBY_DOCDIR}/syslog

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
