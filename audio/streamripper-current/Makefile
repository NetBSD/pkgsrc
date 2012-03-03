# $NetBSD: Makefile,v 1.4 2012/03/03 00:12:44 wiz Exp $
#

DISTNAME=	streamripper-1.64.3
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=streamripper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://streamripper.sourceforge.net/
COMMENT=	Splits SHOUTcast stream into tracks

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-tre
BUILDLINK_API_DEPENDS.tre+=	tre>=0.7.5nb1
CONFIGURE_ARGS+=	--without-included-libmad
USE_TOOLS+=	pkg-config

PTHREAD_OPTS+=	require

.include "options.mk"

.include "../../audio/libmad/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
