# $NetBSD: Makefile,v 1.3 1999/10/04 20:39:23 hubertf Exp $
#

DISTNAME=	libggi-2.0b2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ggi-project.org/pub/ggi/ggi/current/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ggi-project.org/

DEPENDS+=	libgii-0.6:../libgii
DEPENDS+=	ncurses-4.2:../../devel/ncurses

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--disable-debug \
		--with-x \
		--with-extra-includes=${LOCALBASE}/include

post-install:
	cd ${PREFIX}/man/man3 ; for i in *.3ggi ; do \
		${MV} $$i `basename $$i .3ggi`.3 ; \
	done
	cd ${PREFIX}/man/man7 ; for i in *.7ggi ; do \
		${MV} $$i `basename $$i .7ggi`.7 ; \
	done

.include "../../mk/bsd.pkg.mk"
