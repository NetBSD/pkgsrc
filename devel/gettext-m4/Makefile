# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:04 rillig Exp $

DISTNAME=		gettext-0.11.5
PKGNAME=		gettext-m4-0.11.5
SVR4_PKGNAME=		gttm4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Autoconf/automake m4 files for GNU NLS library

CONFLICTS=		gettext<=0.10.35nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-included-gettext
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}

BUILD_DIRS=		${WRKSRC}/m4

.include "../../mk/bsd.pkg.mk"
