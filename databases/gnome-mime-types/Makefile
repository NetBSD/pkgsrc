# $NetBSD: Makefile,v 1.3 2002/08/25 19:22:07 jlam Exp $
#

DISTNAME=		gnome-mime-data-1.0.7
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/gnome-mime-data/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		MIME and Application database for GNOME2

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
