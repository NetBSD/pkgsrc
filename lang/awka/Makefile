# $NetBSD: Makefile,v 1.15 2020/03/20 11:57:55 nia Exp $

DISTNAME=	awka-0.7.5
PKGREVISION=	3
CATEGORIES=	lang devel
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://awka.sourceforge.net/
COMMENT=	AWK to ANSI C compiler
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			MANSRCDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
