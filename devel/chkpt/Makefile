# $NetBSD: Makefile,v 1.1.1.1 1998/11/11 12:47:22 agc Exp $
#

DISTNAME=	chkpt-1.6.1
CATEGORIES=	devel
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/chkpt/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=

ALL_TARGET=	libcc.a

post-patch:
	@cd ${WRKSRC}/utils;						\
	for f in ccc-NetBSD cf77-NetBSD; do				\
		${MV} $$f $$f.in;					\
		${SED} -e 's|/usr/local|${PREFIX}|g' $$f.in > $$f;	\
	done

.include "../../mk/bsd.pkg.mk"
