# $NetBSD: Makefile,v 1.4 2003/07/17 21:22:58 grant Exp $

DISTNAME=	mpg321-0.2.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink
USE_BUILDLINK2=		yes

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
