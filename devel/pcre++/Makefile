# $NetBSD: Makefile,v 1.1.1.1 2004/12/26 22:09:49 zuntum Exp $
#

DISTNAME=		pcre++-0.9.5
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		ftp://ftp.daemon.de/scip/Apps/pcre++/
COMMENT=		wrapper class around the pcre library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
