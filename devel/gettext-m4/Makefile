# $NetBSD: Makefile,v 1.10 2004/02/17 11:23:45 jlam Exp $

DISTNAME=		gettext-0.11.5
PKGNAME=		gettext-m4-0.11.5
SVR4_PKGNAME=		gttm4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Autoconf/automake m4 files for GNU NLS library

CONFLICTS=		gettext<=0.10.35nb1

NO_BUILDLINK=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-included-gettext
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

BUILD_DIRS=		${WRKSRC}/m4

.include "../../mk/bsd.pkg.mk"
