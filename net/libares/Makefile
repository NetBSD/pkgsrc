# $NetBSD: Makefile,v 1.7 2007/02/22 19:26:53 wiz Exp $
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

CFLAGS.Darwin+=		-DBIND_8_COMPAT

.include "../../mk/bsd.pkg.mk"
