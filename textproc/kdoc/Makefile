# $NetBSD: Makefile,v 1.17 2004/11/13 21:28:28 jlam Exp $

DISTNAME=	kdoc-2.0a54
PKGNAME=	kdoc-3.0
CATEGORIES=	textproc kde

MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.uk.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/3.0/src/

MAINTAINER=	wulf@NetBSD.org
COMMENT=	C++ and IDL Class Documentation Tool

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=	yes

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
