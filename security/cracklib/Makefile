# $NetBSD: Makefile,v 1.2 2023/08/14 05:25:09 wiz Exp $

DISTNAME=	cracklib-2.9.7
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=cracklib/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cracklib/cracklib
COMMENT=	Library used to enforce strong passwords
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt msgmerge xgettext

CONFIGURE_ARGS+=	--with-default-dict=${PREFIX}/share/cracklib/cracklib-small
CONFIGURE_ARGS+=	--without-python

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
