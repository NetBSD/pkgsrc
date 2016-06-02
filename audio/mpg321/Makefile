# $NetBSD: Makefile,v 1.19 2016/06/02 09:18:19 jperkin Exp $

DISTNAME=	mpg321_0.3.2.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mpg321/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mpg321.sourceforge.net/
COMMENT=	Free replacement for mpg123
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-mpg123-symlink

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig/-orig/}

.include "options.mk"

.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
