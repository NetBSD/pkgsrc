# $NetBSD: Makefile,v 1.10 2003/11/10 02:03:17 xtraeme Exp $
#

DISTNAME=	gqview-1.3.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer (development version)

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG=no

.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
