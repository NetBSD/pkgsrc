# $NetBSD: Makefile,v 1.2 2001/02/16 15:22:26 wiz Exp $
#

DISTNAME=	libgii-0.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/current/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ggi-project.org/
COMMENT=	General Input Interface - API for all possible input sources

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-mutexes=int \
		--with-x

post-install:
	cd ${PREFIX}/man/man3 ; for i in *.3gii ; do \
		${MV} $$i `basename $$i .3gii`.3 ; \
	done

.include "../../mk/bsd.pkg.mk"
