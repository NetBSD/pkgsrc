# $NetBSD: Makefile,v 1.6 2006/04/17 13:46:32 wiz Exp $

DISTNAME=	gocr-0.40
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jocr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/jocr
COMMENT=	GOCR is a set of OCR tools

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-netpbm=${BUILDLINK_PREFIX.netpbm}

.include "options.mk"

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
