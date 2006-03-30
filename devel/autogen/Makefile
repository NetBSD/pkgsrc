# $NetBSD: Makefile,v 1.23 2006/03/30 03:44:42 jlam Exp $

DISTNAME=	autogen-5.8.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Text and Program Generation Tool

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		# PLIST

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/autoopts

.include "../../lang/guile/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
