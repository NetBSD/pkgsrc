# $NetBSD: Makefile,v 1.12 2015/02/14 01:27:15 mef Exp $
#

DISTNAME=		pcre++-0.9.5
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.daemon.de/idisk/Apps/pcre++/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.daemon.de/PCRE
COMMENT=		Wrapper class around the pcre library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
