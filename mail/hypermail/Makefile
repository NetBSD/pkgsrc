# $NetBSD: Makefile,v 1.11 2006/06/20 22:14:46 minskim Exp $
#

DISTNAME=	hypermail-2.1.8
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	grant@NetBSD.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	Creates indexed, threaded HTML archives of email

GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc

CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/hypermail

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
