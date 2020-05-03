# $NetBSD: Makefile,v 1.16 2020/05/03 15:36:20 rillig Exp $

DISTNAME=	awka-0.7.5
PKGREVISION=	4
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
