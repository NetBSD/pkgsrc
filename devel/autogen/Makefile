# $NetBSD: Makefile,v 1.27 2008/06/20 01:09:11 joerg Exp $

DISTNAME=	autogen-5.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Text and Program Generation Tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

INSTALLATION_DIRS=	include/autoopts

.include "../../lang/guile/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
