# $NetBSD: Makefile,v 1.2 2006/12/01 20:22:19 joerg Exp $
#

DISTNAME=	libsylph-0.3.0
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed.sraoss.jp/sylpheed/libsylph/alpha/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://sylpheed.sraoss.jp/
COMMENT=	E-Mail client library

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

USE_TOOLS+=		lex pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
