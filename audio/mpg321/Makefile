# $NetBSD: Makefile,v 1.17 2012/10/02 23:48:00 asau Exp $

DISTNAME=	mpg321-0.2.13-4
PKGNAME=	mpg321-0.2.13.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
