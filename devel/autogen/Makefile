# $NetBSD: Makefile,v 1.18 2005/04/11 21:45:18 tv Exp $

DISTNAME=	autogen-5.6.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Program Generator

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_MAKEINFO=		YES
INFO_FILES=		autogen.info

.include "../../lang/guile/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
