# $NetBSD: Makefile,v 1.4 2003/07/13 13:52:04 wiz Exp $
#

DISTNAME=		gnome-icon-theme-1.0.2
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		theme consisting of a set of icons for GNOME

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
