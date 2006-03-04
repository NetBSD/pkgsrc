# $NetBSD: Makefile,v 1.5 2006/03/04 21:29:48 jlam Exp $

DISTNAME=	gocr-0.40
PKGREVISION=	1
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
