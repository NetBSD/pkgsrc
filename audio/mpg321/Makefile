# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:08 tv Exp $

DISTNAME=	mpg321-0.2.10
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink
USE_BUILDLINK3=		yes

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
