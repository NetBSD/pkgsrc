# $NetBSD: Makefile,v 1.3 1998/12/28 02:48:38 tv Exp $
#

DISTNAME=	libscsi-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	packages@netbsd.org

MAKE_ENV=	LIBDIR=${PREFIX}/lib MANDIR=${PREFIX}/man NOPIC=1 NOPROFILE=1

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=	yes
.endif

.include "../../mk/bsd.pkg.mk"
