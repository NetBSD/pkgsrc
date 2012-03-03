# $NetBSD: Makefile,v 1.10 2012/03/03 00:12:07 wiz Exp $
#

DISTNAME=	libsylph-0.3.0
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/libsylph/alpha/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sylpheed.sraoss.jp/
COMMENT=	E-Mail client library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		lex pkg-config msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
