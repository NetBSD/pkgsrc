# $NetBSD: Makefile,v 1.2 2002/08/25 18:40:02 jlam Exp $
#

DISTNAME=		intltool-0.18
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/intltool/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
