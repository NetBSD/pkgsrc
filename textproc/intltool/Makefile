# $NetBSD: Makefile,v 1.1.1.1 2002/05/06 13:15:21 rh Exp $
#

DISTNAME=		intltool-0.18
CATEGORIES=		textproc devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/intltool/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Toolbox for internationalisation

USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
