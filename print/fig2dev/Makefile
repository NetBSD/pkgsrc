# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:28 rillig Exp $

DISTNAME=	fig2dev-3.2.6a
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mcj.sourceforge.net/
COMMENT=	Convert .fig files to graphical or printable formats

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-liconv

.include "../../graphics/png/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
