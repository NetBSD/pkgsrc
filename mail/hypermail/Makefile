# $NetBSD: Makefile,v 1.8 2004/10/03 00:12:53 tv Exp $
#

DISTNAME=	hypermail-2.1.7
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	Creates indexed, threaded HTML archives of email

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/hypermail

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hypermail/images

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
