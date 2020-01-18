# $NetBSD: Makefile,v 1.11 2020/01/18 23:30:10 rillig Exp $
#

DISTNAME=	cascade-1.4
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rfcascade/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://rfcascade.sourceforge.net/
COMMENT=	Simple tool to analyze noise and distortion of a RF system

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
