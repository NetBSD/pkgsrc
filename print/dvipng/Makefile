# $NetBSD: Makefile,v 1.3 2003/08/30 15:59:40 wiz Exp $
#

DISTNAME=		dvipng-0.6
CATEGORIES=		textproc converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=preview-latex/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://preview-latex.sourceforge.net/
COMMENT=		Convert DVI files to PNG files

USE_BUILDLINK2=		yes
USE_MAKEINFO=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INFO_FILES=		dvipng.info

.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../print/teTeX2-bin/kpathsea.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
