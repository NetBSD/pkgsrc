# $NetBSD: Makefile,v 1.3 2002/10/19 10:54:43 rh Exp $
#

DISTNAME=		gnome-mime-data-2.0.1
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-mime-data/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		MIME and Application database for GNOME2

CONFLICTS=		gnome-vfs-1*

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PERL5=		build
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
