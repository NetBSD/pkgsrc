# $NetBSD: Makefile,v 1.1.1.1 2000/03/03 13:45:23 hubertf Exp $
#

DISTNAME=	libIDL-0.6.8
CATEGORIES=	devel
MASTER_SITES=	http://atv.ne.mediaone.net/libIDL/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://atv.ne.mediaone.net/libIDL/

DEPENDS=	glib-1.2.*:../../devel/glib

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-glib-prefix=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
