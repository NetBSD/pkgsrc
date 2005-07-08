# $NetBSD: Makefile,v 1.20 2005/07/08 20:53:49 kristerw Exp $

DISTNAME=	kdoc-2.0a54
PKGNAME=	kdoc-3.0
PKGREVISION=	1
CATEGORIES=	textproc kde

MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.uk.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/3.0/src/

MAINTAINER=	wulf@NetBSD.org
COMMENT=	C++ and IDL Class Documentation Tool

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	do-configure
SUBST_FILES.vars=	Makefile.in
SUBST_SED.vars=		-e 's|@perl@|${PERL5}|g'

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
