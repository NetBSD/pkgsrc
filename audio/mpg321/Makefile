# $NetBSD: Makefile,v 1.2 2002/08/31 03:26:33 wiz Exp $

DISTNAME=	mpg321-0.2.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink
USE_BUILDLINK2=		yes

.include "../../audio/libao/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
