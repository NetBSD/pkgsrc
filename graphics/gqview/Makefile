# $NetBSD: Makefile,v 1.41 2004/02/21 07:59:52 snj Exp $
#

DISTNAME=	gqview-1.4.0
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		# defined
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG=no

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
