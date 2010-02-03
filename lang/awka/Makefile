# $NetBSD: Makefile,v 1.9 2010/02/03 23:33:58 joerg Exp $
#

DISTNAME=	awka-0.7.5
PKGREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://awka.sourceforge.net/
COMMENT=	AWK to ANSI C compiler

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			MANSRCDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
