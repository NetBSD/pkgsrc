# New ports collection makefile for:	MIT pthreads
# Version required:     1.60beta6
# Date created:		10th October 1997
# Whom:			Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.7 1998/03/10 21:35:14 agc Exp $
#

DISTNAME=       pthreads-1_60_beta6
PKGNAME=        mit-pthreads-1.60b6
CATEGORIES=	devel
MASTER_SITES=   ftp://sipb.mit.edu/pub/pthreads/
ONLY_FOR_ARCHS=	alpha arm32 bebox i386 mips pc532 powerpc sparc vax

MAINTAINER=	agc@netbsd.org

GNU_CONFIGURE=	yes
MAKE_ENV+=	NOLINT=1

pre-install:
	-mkdir ${PREFIX}/pthreads

post-install:
	find ${PREFIX}/pthreads/include -type f -print|xargs chmod 644
	find ${PREFIX}/pthreads/include -type d -print|xargs chmod 755

.include <bsd.port.mk>
