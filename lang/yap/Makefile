# $NetBSD: Makefile,v 1.5 2008/03/04 11:02:25 rillig Exp $
#

DISTNAME=		Yap-5.0.0
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yap/}
DIST_SUBDIR=		${PKGNAME_NOREV}-1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ncc.up.pt/~vsc/Yap/
COMMENT=		ISO-compliant Prolog

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		INDENT=${TRUE:Q}

.include "../../mk/bsd.pkg.mk"
