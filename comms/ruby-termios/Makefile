# $NetBSD: Makefile,v 1.1.1.1 2000/07/08 16:06:45 sakamoto Exp $
#

DISTNAME=	ruby-termios-module-0.0.4
CATEGORIES=	comms
MASTER_SITES=	ftp://arika.org/pub/Tools/Ruby/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://arika.org/ruby/termios.html

DEPENDS+=	ruby-1.4.*:../../lang/ruby

RUBY_VERSION=	1.4
PLIST_SUBST=	RUBY_VERSION=${RUBY_VERSION}

do-configure:
	(cd ${WRKSRC}; ruby extconf.rb)

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ruby/termios
	${INSTALL_DATA} ${WRKSRC}/test[0-3].rb \
		${PREFIX}/share/examples/ruby/termios

.include "../../mk/bsd.pkg.mk"
