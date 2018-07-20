# $NetBSD: Makefile,v 1.26 2018/07/20 03:34:05 ryoon Exp $
#

DISTNAME=	msynctool-0.22
PKGREVISION=	21
CATEGORIES=	comms
##MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.opensync.org/
COMMENT=	Command line tool for opensync framework

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../comms/libopensync/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
