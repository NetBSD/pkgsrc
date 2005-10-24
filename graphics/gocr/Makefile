# $NetBSD: Makefile,v 1.2 2005/10/24 15:01:37 rillig Exp $

DISTNAME=	gocr-0.37
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jocr/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/jocr
COMMENT=	GOCR is a set of OCR tools

GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
USE_TOOLS+=		gmake

.include "../../mk/bsd.pkg.mk"
