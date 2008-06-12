# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:33 joerg Exp $
#

DISTNAME=		Yap-5.0.0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yap/}
DIST_SUBDIR=		${PKGNAME_NOREV}-1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ncc.up.pt/~vsc/Yap/
COMMENT=		ISO-compliant Prolog

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		INDENT=${TRUE:Q}

.include "../../mk/bsd.pkg.mk"
