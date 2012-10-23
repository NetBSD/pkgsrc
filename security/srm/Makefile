# $NetBSD: Makefile,v 1.6 2012/10/23 18:16:59 asau Exp $
#

DISTNAME=		srm-1.2.8
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=srm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://srm.sourceforge.net/
COMMENT=		Secure replacement for rm(1)

GNU_CONFIGURE=		yes

CONFLICTS+=		sr-[0-9]* # bin/srm

.include "../../mk/bsd.pkg.mk"
