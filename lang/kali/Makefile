# $NetBSD: Makefile,v 1.10 2008/09/06 22:37:04 dholland Exp $

DISTNAME=	kali-0.47
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.nj.nec.com/pub/pls/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.neci.nj.nec.com/PLS/Kali.html
COMMENT=	Distributed implementation of Scheme

GNU_CONFIGURE=	yes
BUILD_TARGET=	# empty
INSTALLATION_DIRS=	bin include lib

# Thoroughly broken on 64-bit architectures.
NOT_FOR_PLATFORM=	*-*-alpha *-*-sparc64 *-*-x86_64

.include "../../mk/bsd.pkg.mk"
