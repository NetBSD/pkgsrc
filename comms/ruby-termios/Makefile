# $NetBSD: Makefile,v 1.4 2003/07/17 21:27:00 grant Exp $
#

DISTNAME=	termios
PKGNAME=	${RUBY_PKGNAMEPREFIX}termios-0.0.4
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.ruby-lang.org/pub/ruby/contrib/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://arika.org/ruby/termios.html
COMMENT=	Ruby extention to termios library

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/termios
	${INSTALL_DATA} ${WRKSRC}/test/test[0-3].rb ${RUBY_EXAMPLESDIR}/termios

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
