# $NetBSD: Makefile,v 1.12 2007/08/13 06:31:36 rillig Exp $

DISTNAME=	mpg321-0.2.10
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
