# $NetBSD: Makefile,v 1.21 2006/03/05 16:27:24 jlam Exp $

DISTNAME=	autogen-5.6.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Program Generator

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		autogen.info

.include "../../lang/guile/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
