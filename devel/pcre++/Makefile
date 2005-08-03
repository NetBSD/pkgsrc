# $NetBSD: Makefile,v 1.4 2005/08/03 17:44:17 wiz Exp $
#

DISTNAME=		pcre++-0.9.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		ftp://ftp.daemon.de/scip/Apps/pcre++/
COMMENT=		Wrapper class around the pcre library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
