# $NetBSD: Makefile,v 1.2 2001/02/16 13:56:23 wiz Exp $
#

DISTNAME=	ruby-termios-module-0.0.4
CATEGORIES=	comms
MASTER_SITES=	ftp://arika.org/pub/Tools/Ruby/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://arika.org/ruby/termios.html
COMMENT=	termios module for Ruby

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
