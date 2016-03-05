# $NetBSD: Makefile,v 1.16 2016/03/05 11:27:50 jperkin Exp $
#

DISTNAME=	libsylph-1.1.0
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/libsylph/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sylpheed.sraoss.jp/
COMMENT=	E-Mail client library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		lex pkg-config msgfmt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
