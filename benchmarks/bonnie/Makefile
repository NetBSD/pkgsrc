# New ports collection makefile for:    bonnie
# Version required:     1.0
# Date created:         26 September 1994
# Whom:                 se
#
# $NetBSD: Makefile,v 1.5 1998/03/20 22:04:08 frueauf Exp $
# $FreeBSD Id: Makefile,v 1.5 1997/11/26 23:09:14 jseger Exp
#

DISTNAME=       Bonnie
PKGNAME=	bonnie-1.0
CATEGORIES=	benchmarks
MASTER_SITES=   ftp://ftp.sunet.se/pub/benchmark/Bonnie/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	se@FreeBSD.org

NO_CONFIGURE=	yes

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

post-extract:
	${MV} ${WRKSRC}/Bonnie.c ${WRKSRC}/bonnie.c

.include <bsd.port.mk>
