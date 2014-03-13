# $NetBSD: Makefile,v 1.27 2014/03/13 18:10:52 taca Exp $

DISTNAME=	ruby-termios-0.9.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	2
CATEGORIES=	comms

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://arika.org/ruby/termios
COMMENT=	Ruby extension to termios library
LICENSE=	gnu-gpl-v2 OR ruby-license

GEM_CLEANBUILD=	Makefile *.o *.time termios.${RUBY_DLEXT} mkmf.log \
		.RUBYARCHDIR.time
GEM_CLEANBUOLD_EXTENSIONS=	termios.rb

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
