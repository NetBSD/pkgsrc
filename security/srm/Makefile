# $NetBSD: Makefile,v 1.5 2012/10/05 17:17:04 cheusov Exp $
#

DISTNAME=		srm-1.2.8
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=srm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://srm.sourceforge.net/
COMMENT=		Secure replacement for rm(1)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFLICTS+=		sr-[0-9]* # bin/srm

.include "../../mk/bsd.pkg.mk"
