# $NetBSD: Makefile,v 1.4 2002/11/30 16:24:35 salo Exp $
#

DISTNAME=		gnome-mime-data-2.0.1
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-mime-data/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		MIME and Application database for GNOME2

BUILD_USES_MSGFMT=	YES

CONFLICTS=		gnome-vfs-1*

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_PERL5=		build
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
