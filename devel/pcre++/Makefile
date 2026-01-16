# $NetBSD: Makefile,v 1.14 2026/01/16 06:52:24 wiz Exp $

DISTNAME=		pcre++-0.9.5
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.daemon.de/idisk/Apps/pcre++/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.daemon.de/projects/archive/
COMMENT=		Wrapper class around the pcre library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
