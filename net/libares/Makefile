# $NetBSD: Makefile,v 1.6 2005/11/20 15:08:35 tonio Exp $
#

DISTNAME=	ares-1.1.1
PKGNAME=	libares-1.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/ares/

MAINTAINER=	sommerfeld@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Asynchronous DNS resolver library

GNU_CONFIGURE=	YES

CFLAGS.Darwin+=         -DBIND_8_COMPAT

.include "../../mk/bsd.pkg.mk"
