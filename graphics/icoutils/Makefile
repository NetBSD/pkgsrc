# $NetBSD: Makefile,v 1.5 2019/08/11 13:21:11 wiz Exp $

DISTNAME=	icoutils-0.32.2
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://savannah.nongnu.org/download/icoutils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/icoutils/
COMMENT=	Tools for Microsoft Windows icon and cursor files
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run

REPLACE_PERL+=		extresso/extresso.in
REPLACE_PERL+=		extresso/genresscript.in

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
