# $NetBSD: Makefile,v 1.11 2005/01/28 14:08:01 taca Exp $
#

DISTNAME=	ruby-termios-0.9.4
PKGNAME=	${RUBY_PKGPREFIX}-termios-0.9.4
PKGREVISION=	1
CATEGORIES=	comms ruby
MASTER_SITES=	http://arika.org/archive/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://arika.org/ruby/termios
COMMENT=	Ruby extension to termios library

RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes

DOCS=			ChangeLog README TODO.ja
EXAMPLES=		modem_check0.rb modem_check1.rb modem_check2.rb \
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

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
