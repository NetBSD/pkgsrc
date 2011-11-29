# $NetBSD: Makefile,v 1.26 2011/11/29 18:32:41 hans Exp $

DISTNAME=	kdoc-2.0a54
PKGNAME=	kdoc-3.0
PKGREVISION=	2
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_KDE:=3.0/src/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	C++ and IDL Class Documentation Tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run pod2man

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_FILES.vars=	Makefile.in
SUBST_SED.vars=		-e 's|@perl@|${PERL5}|g'

.include "../../meta-pkgs/kde3/Makefile.kde3"
.include "../../mk/bsd.pkg.mk"
