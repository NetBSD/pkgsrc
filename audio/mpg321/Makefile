# $NetBSD: Makefile,v 1.1.1.1 2002/06/13 09:14:45 rh Exp $

DISTNAME=	mpg321-0.2.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink

.include "../../audio/libao/buildlink.mk"
.include "../../audio/mad/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
