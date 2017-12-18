# $NetBSD: Makefile,v 1.2 2017/12/18 13:06:15 jperkin Exp $

DISTNAME=	fig2dev-3.2.6a
CATEGORIES=	graphics print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcj.sourceforge.net/
COMMENT=	Convert .fig files to graphical or printable formats

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-liconv

.include "../../graphics/png/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
