# $NetBSD: Makefile,v 1.5 2003/07/13 08:25:29 wiz Exp $
#

DISTNAME=	pfaedit_full-${VERSION}
PKGNAME=	pfaedit-20${VERSION}
WRKSRC=		${WRKDIR}/pfaedit-${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	http://pfaedit.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://pfaedit.sourceforge.net/
COMMENT=	postscript font editor

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
