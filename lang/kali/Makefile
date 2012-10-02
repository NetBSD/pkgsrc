# $NetBSD: Makefile,v 1.14 2012/10/02 20:11:44 asau Exp $

DISTNAME=	kali-0.52.2
CATEGORIES=	lang
MASTER_SITES=	http://community.schemewiki.org/kali-scheme/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://community.schemewiki.org/kali-scheme/
COMMENT=	Distributed implementation of Scheme

GNU_CONFIGURE=	yes
BUILD_TARGET=	# empty
MAKE_ENV=	mandir=$(PREFIX)/$(PKGMANDIR)/man1
INSTALLATION_DIRS=	bin include lib $(PKGMANDIR)/man1

# Thoroughly broken on 64-bit architectures.
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

.include "../../mk/bsd.pkg.mk"
