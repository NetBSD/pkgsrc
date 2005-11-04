# $NetBSD: Makefile,v 1.4 2005/11/04 17:38:02 rillig Exp $
#

DISTNAME=		Yap-5.0.0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yap/}
DIST_SUBDIR=		${PKGNAME_NOREV}-1

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.ncc.up.pt/~vsc/Yap/
COMMENT=		ISO-compliant Prolog

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		INDENT=${TRUE:Q}

.include "../../mk/bsd.pkg.mk"
