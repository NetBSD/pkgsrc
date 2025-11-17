# $NetBSD: Makefile,v 1.18 2025/11/17 11:01:01 wiz Exp $

DISTNAME=	awka-0.7.5
PKGREVISION=	4
CATEGORIES=	lang devel
MASTER_SITES=	http://sourceforge.net/projects/awka/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://awka.sourceforge.net/
COMMENT=	AWK to ANSI C compiler
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			MANSRCDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
