# $NetBSD: Makefile,v 1.14 2025/11/17 11:00:26 wiz Exp $
#

DISTNAME=	cascade-1.4
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rfcascade/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rfcascade.sourceforge.net/
COMMENT=	Simple tool to analyze noise and distortion of a RF system

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
