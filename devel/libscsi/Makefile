# $NetBSD: Makefile,v 1.2 1998/06/20 09:20:39 agc Exp $
#

DISTNAME=	libscsi-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	packages@netbsd.org

MAKE_ENV=	LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
