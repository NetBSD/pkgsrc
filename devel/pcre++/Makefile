# $NetBSD: Makefile,v 1.8 2007/12/30 14:36:54 obache Exp $
#

DISTNAME=		pcre++-0.9.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.daemon.de/files/mirror/ftp.daemon.de/scip/Apps/pcre++/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.daemon.de/PCRE
COMMENT=		Wrapper class around the pcre library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
