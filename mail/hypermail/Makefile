# $NetBSD: Makefile,v 1.3 2002/11/01 16:34:40 wiz Exp $
#

DISTNAME=	hypermail-2.1.4
PKGREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	creates indexed, threaded HTML archives of email

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/hypermail

.include "../../databases/gdbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
