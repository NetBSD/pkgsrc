# $NetBSD: Makefile,v 1.14 2020/01/18 23:32:41 rillig Exp $

DISTNAME=	awka-0.7.5
PKGREVISION=	3
CATEGORIES=	lang devel
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://awka.sourceforge.net/
COMMENT=	AWK to ANSI C compiler
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			MANSRCDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
