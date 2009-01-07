# $NetBSD: Makefile,v 1.7 2009/01/07 18:45:54 drochner Exp $
#

DISTNAME=	streamripper-1.61.27
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=streamripper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://streamripper.sourceforge.net/
COMMENT=	Splits SHOUTcast stream into tracks

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

PTHREAD_OPTS+=	require

.include "options.mk"

.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
