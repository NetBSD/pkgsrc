# $NetBSD: Makefile,v 1.6 2003/07/21 16:56:45 martti Exp $
#

DISTNAME=	hypermail-2.1.7
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	Creates indexed, threaded HTML archives of email

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/hypermail

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hypermail/images

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
