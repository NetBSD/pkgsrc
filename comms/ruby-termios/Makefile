# $NetBSD: Makefile,v 1.6 2003/09/19 23:08:26 dent Exp $
#

DISTNAME=	ruby-termios-0.9.4
PKGNAME=	${RUBY_PKGNAMEPREFIX}termios-0.9.4
CATEGORIES=	comms
MASTER_SITES=	http://arika.org/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://arika.org/ruby/termios
COMMENT=	Ruby extention to termios library

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
DOCS=		ChangeLog README TODO.ja
EXAMPLES=	modem_check0.rb modem_check1.rb modem_check2.rb \
		secret_input1.rb secret_input2.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/termios
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/$f ${RUBY_DOCDIR}/termios
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/termios
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/$f ${RUBY_EXAMPLESDIR}/termios
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
