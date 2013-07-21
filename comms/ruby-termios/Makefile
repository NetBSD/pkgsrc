# $NetBSD: Makefile,v 1.26 2013/07/21 02:38:24 taca Exp $

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

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
