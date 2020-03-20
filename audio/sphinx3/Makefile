# $NetBSD: Makefile,v 1.5 2020/03/20 11:57:23 nia Exp $

DISTNAME=	sphinx3-0.8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cmusphinx/}

MAINTAINER=	fhajny@NetBSD.org
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
