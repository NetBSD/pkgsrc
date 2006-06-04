# $NetBSD: Makefile,v 1.7 2006/06/04 21:49:54 joerg Exp $
#

DISTNAME=		pcre++-0.9.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.daemon.de/scip/Apps/pcre++/
COMMENT=		Wrapper class around the pcre library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
