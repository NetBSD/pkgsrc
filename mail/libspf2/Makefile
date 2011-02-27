# $NetBSD: Makefile,v 1.8 2011/02/27 13:06:12 obache Exp $

DISTNAME=	libspf2-1.2.9
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFLICTS+=	libspf_alt-[0-9]*
CONFLICTS+=	p5-Mail-SPF-[0-9]*

.include "../../mk/bsd.pkg.mk"
