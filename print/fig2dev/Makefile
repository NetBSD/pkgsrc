# $NetBSD: Makefile,v 1.11 2025/11/17 11:01:19 wiz Exp $

DISTNAME=	fig2dev-3.2.8b
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mcj.sourceforge.net/
COMMENT=	Convert .fig files to graphical or printable formats

GNU_CONFIGURE=	yes

USE_TOOLS+=	gs:run

.include "../../graphics/png/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
