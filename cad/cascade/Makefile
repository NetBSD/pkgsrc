# $NetBSD: Makefile,v 1.9 2012/10/08 13:25:11 asau Exp $
#

DISTNAME=	cascade-1.4
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rfcascade/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://rfcascade.sourceforge.net/
COMMENT=	Simple tool to analyze noise and distortion of a RF system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
