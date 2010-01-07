# $NetBSD: Makefile,v 1.12 2010/01/07 07:36:54 wiz Exp $

DISTNAME=	kali-0.47
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.nj.nec.com/pub/pls/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.neci.nj.nec.com/PLS/Kali.html
COMMENT=	Distributed implementation of Scheme

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
BUILD_TARGET=	# empty
MAKE_ENV=	mandir=$(PREFIX)/$(PKGMANDIR)/man1
INSTALLATION_DIRS=	bin include lib $(PKGMANDIR)/man1

# Thoroughly broken on 64-bit architectures.
NOT_FOR_PLATFORM=	${LP64PLATFORMS}

.include "../../mk/bsd.pkg.mk"
