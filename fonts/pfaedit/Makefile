# $NetBSD: Makefile,v 1.8 2004/01/03 18:49:40 reed Exp $
#

DISTNAME=	pfaedit_full-${VERSION}
PKGNAME=	pfaedit-20${VERSION}
PKGREVISION=			1
WRKSRC=		${WRKDIR}/pfaedit-${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	http://pfaedit.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pfaedit.sourceforge.net/
COMMENT=	Postscript font editor

VERSION=	030712

USE_GMAKE=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
