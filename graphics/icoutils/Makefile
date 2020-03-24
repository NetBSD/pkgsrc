# $NetBSD: Makefile,v 1.8 2020/03/24 06:29:40 rillig Exp $

DISTNAME=	icoutils-0.32.3
PKGREVISION=	2
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
