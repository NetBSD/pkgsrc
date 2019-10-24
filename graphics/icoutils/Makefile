# $NetBSD: Makefile,v 1.7 2019/10/24 20:43:21 nia Exp $

DISTNAME=	icoutils-0.32.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://savannah.nongnu.org/download/icoutils/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/icoutils/
COMMENT=	Tools for Microsoft Windows icon and cursor files
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run
USE_TOOLS+=	msgfmt msgmerge xgettext

REPLACE_PERL+=		extresso/extresso.in
REPLACE_PERL+=		extresso/genresscript.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
