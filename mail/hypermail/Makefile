# $NetBSD: Makefile,v 1.1.1.1 2002/06/26 05:52:05 grant Exp $
#

DISTNAME=	hypermail-2.1.4
CATEGORIES=	mail www
MASTER_SITES=	http://www.hypermail.org/dist/

MAINTAINER=	grant@netbsd.org
HOMEPAGE=	http://www.hypermail.org/
COMMENT=	creates indexed, threaded HTML archives of email

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/hypermail

.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
