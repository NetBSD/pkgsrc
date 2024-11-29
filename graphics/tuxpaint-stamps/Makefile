# $NetBSD: Makefile,v 1.21 2024/11/29 22:56:40 wiz Exp $

DISTNAME=	tuxpaint-stamps-2024.10.25
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxpaint.org/
COMMENT=	Rubber stamps for Tux Paint
LICENSE=	gnu-gpl-v2

#DEPENDS+=	tuxpaint>=0.9.13:../../graphics/tuxpaint

CONFLICTS+=	tuxpaint<0.9.13

INSTALL_TARGET=		install-all
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
