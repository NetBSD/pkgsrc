# $NetBSD: Makefile,v 1.15 2006/07/26 06:53:02 adam Exp $

DISTNAME=	gettext-0.14.6
PKGNAME=	gettext-m4-0.14.6
SVR4_PKGNAME=	gttm4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gettext/gettext.html
COMMENT=	Autoconf/automake m4 files for GNU NLS library

CONFLICTS=		gettext<=0.10.35nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/aclocal

do-install:
	${INSTALL_DATA} ${WRKSRC:Q}/gettext-runtime/m4/*.m4 ${PREFIX}/share/aclocal
	${INSTALL_DATA} ${WRKSRC:Q}/autoconf-lib-link/m4/*.m4 ${PREFIX}/share/aclocal

.include "../../mk/bsd.pkg.mk"
