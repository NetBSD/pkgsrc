# $NetBSD: Makefile,v 1.22.4.1 2011/02/27 00:26:12 tron Exp $

DISTNAME=	ruby-termios-0.9.6
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	comms

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://arika.org/ruby/termios
COMMENT=	Ruby extension to termios library
LICENSE=	gnu-gpl-v2 OR ruby-license

GEM_CLEANBUILD=	Makefile *.o termios.${RUBY_DLEXT} mkmf.log

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
