# $NetBSD: Makefile,v 1.1.1.1 2008/09/14 12:25:30 ahoka Exp $

PKGNAME=		fricas-1.0.3
DISTNAME=		${PKGNAME}-full
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fricas/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://fricas.sourceforge.net/
COMMENT=		FriCAS is a fork of the Axiom computer algebra system

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

BUILD_DEPENDS+=		noweb-[0-9]*:../../devel/noweb

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
