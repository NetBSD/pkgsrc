# $NetBSD: Makefile,v 1.1.1.1 1999/06/23 18:18:53 drochner Exp $
#

DISTNAME=       chipmunk-1.4
CATEGORIES=	misc
MASTER_SITES=   http://www.bitwizard.nl/chipmunk/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bitwizard.nl/chipmunk/index.html

DEPENDS+=	readline-2.2:../../devel/readline

ONLY_FOR_PLATFORM=	NetBSD-*-i386

ALL_TARGET=	chipmunk
MAKE_FLAGS=	CONFIG_OPTIONS=-I$(PREFIX)/include \
		LDFLAGS=-L$(PREFIX)/lib EXTRA_LIBS=-li386

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/chipmunk $(PREFIX)/sbin/chipmunk

.include "../../mk/bsd.pkg.mk"
