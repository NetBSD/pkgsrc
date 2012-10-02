# $NetBSD: Makefile,v 1.11 2012/10/02 20:11:35 asau Exp $
#

DISTNAME=	awka-0.7.5
PKGREVISION=	3
CATEGORIES=	lang devel
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://awka.sourceforge.net/
COMMENT=	AWK to ANSI C compiler

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			MANSRCDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
