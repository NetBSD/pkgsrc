# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 08:34:16 obache Exp $

DISTNAME=		ebview-0.3.6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ebview/}

MAINTAINER=		yamajun@ofug.net
HOMEPAGE=		http://ebview.sourceforge.net/
COMMENT=		GTK2 based EPWING dictionary browser

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
