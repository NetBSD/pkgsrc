# $NetBSD: Makefile,v 1.9 2003/08/09 10:44:36 seb Exp $

DISTNAME=	autogen-5.5.3
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Program Generator

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_MAKEINFO=		YES
INFO_FILES=		autogen.info

.include "../../lang/guile14/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
