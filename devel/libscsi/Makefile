# $NetBSD: Makefile,v 1.1 1998/05/03 21:23:00 frueauf Exp $
#

DISTNAME=	libscsi-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	packages@netbsd.org

MAKE_ENV=	LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

.include "../../mk/bsd.pkg.mk"
