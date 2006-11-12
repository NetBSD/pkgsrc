# $NetBSD: Makefile,v 1.23 2006/11/12 01:44:57 rillig Exp $

DISTNAME=	kdoc-2.0a54
PKGNAME=	kdoc-3.0
PKGREVISION=	2
CATEGORIES=	textproc kde

MASTER_SITES=	${MASTER_SITE_KDE:=3.0/src/}
MAINTAINER=	wulf@NetBSD.org
COMMENT=	C++ and IDL Class Documentation Tool

USE_TOOLS+=		perl:run

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_FILES.vars=	Makefile.in
SUBST_SED.vars=		-e 's|@perl@|${PERL5}|g'

.include "../../meta-pkgs/kde3/Makefile.kde3"
.include "../../mk/bsd.pkg.mk"
