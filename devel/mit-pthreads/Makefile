# New ports collection makefile for:	MIT pthreads
# Version required:     1.60beta6
# Date created:		10th October 1997
# Whom:			Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.5 1998/01/24 04:22:12 hubertf Exp $
#

DISTNAME=       pthreads-1_60_beta6
PKGNAME=        mit-pthreads-1.60b6
CATEGORIES=	devel
MASTER_SITES=   ftp://sipb.mit.edu/pub/pthreads/

MAINTAINER=	agc@netbsd.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}/pthreads

pre-install:
	-mkdir ${PREFIX}/pthreads

post-install:
	find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755

.include <bsd.port.mk>
