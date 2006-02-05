# $NetBSD: Makefile,v 1.22 2006/02/05 23:11:03 joerg Exp $

DISTNAME=	kdoc-2.0a54
PKGNAME=	kdoc-3.0
PKGREVISION=	2
CATEGORIES=	textproc kde

MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.uk.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/3.0/src/

MAINTAINER=	wulf@NetBSD.org
COMMENT=	C++ and IDL Class Documentation Tool

USE_TOOLS+=		perl:run

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_FILES.vars=	Makefile.in
SUBST_SED.vars=		-e 's|@perl@|${PERL5}|g'

.include "../../meta-pkgs/kde3/Makefile.kde3"
.include "../../mk/bsd.pkg.mk"
