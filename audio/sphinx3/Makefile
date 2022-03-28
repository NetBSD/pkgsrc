# $NetBSD: Makefile,v 1.8 2022/03/28 10:43:39 tnn Exp $

DISTNAME=	sphinx3-0.8
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cmusphinx.sourceforge.net/
COMMENT=	CMUSphinx speech recognition frontend
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sphinx3.pc.in

.include "../../audio/sphinxbase/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
