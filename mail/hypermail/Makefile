# $NetBSD: Makefile,v 1.3.2.1 2003/03/08 12:27:18 grant Exp $
#

DISTNAME=	hypermail-2.1.7
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	creates indexed, threaded HTML archives of email

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/hypermail

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/hypermail/images

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/pcre/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
