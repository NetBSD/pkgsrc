# $NetBSD: Makefile,v 1.3 2003/07/10 10:54:38 adam Exp $

DISTNAME=	mpg321-0.2.10
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink
USE_BUILDLINK2=		yes

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
