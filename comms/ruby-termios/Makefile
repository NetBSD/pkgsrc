# $NetBSD: Makefile,v 1.18 2008/04/04 15:30:00 jlam Exp $

DISTNAME=	ruby-termios-0.9.5
PKGNAME=	${RUBY_PKGPREFIX}-${GEM_NAME}
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://arika.org/archive/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://arika.org/ruby/termios
COMMENT=	Ruby extension to termios library

GEM_NAME=	${DISTNAME:S/ruby-//}
GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile *.o termios.${RUBY_DLEXT} mkmf.log

post-extract:
	cp ${FILESDIR}/gemspec ${GEM_SPECFILE}

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
