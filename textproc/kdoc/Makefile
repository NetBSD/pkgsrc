# $NetBSD: Makefile,v 1.12 2002/11/15 00:16:41 jlam Exp $

DISTNAME=	kdoc-2.0a54
PKGNAME=	kdoc-3.0
CATEGORIES=	textproc kde

MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.uk.kde.org/pub/kde/stable/3.0/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/3.0/src/ 

MAINTAINER=	wulf@netbsd.org
COMMENT=	C++ and IDL Class Documentation Tool

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=	# defined

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
