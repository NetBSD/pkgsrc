# $NetBSD: Makefile,v 1.3 2005/07/12 19:57:57 kristerw Exp $
#

DISTNAME=		pcre++-0.9.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		ftp://ftp.daemon.de/scip/Apps/pcre++/
COMMENT=		wrapper class around the pcre library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
