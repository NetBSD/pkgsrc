# $NetBSD: Makefile,v 1.1.1.1 1997/10/10 19:52:02 agc Exp $
# New ports collection makefile for:	MIT pthreads
# Version required:     1.60beta6
# Date created:		10th October 1997
# Whom:			Alistair Crooks (agc@netbsd.org)
#

DISTNAME=       pthreads-1_60_beta6
PKGNAME=        mit-pthreads-1.60b6
CATEGORIES=	devel
MASTER_SITES=   ftp://sipb.mit.edu/pub/pthreads/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

post-install:
	find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755

.include <bsd.port.mk>
