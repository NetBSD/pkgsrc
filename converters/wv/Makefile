# $NetBSD: Makefile,v 1.30 2003/09/23 10:37:56 adam Exp $
#

DISTNAME=	wv-0.7.6
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://wvware.sourceforge.net/
COMMENT=	Microsoft Word doc to HTML/LaTeX converter

# not detected by configure, causes conflicts with the one coming with wv
#CONFLICTS+=		libgetopt-[0-9]*

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
MAKE_ENV+=		RM="${RM} -f"
MAKEFILE=		GNUmakefile
CONFIGURE_ARGS+=	--with-libwmf=${BUILDLINK_PREFIX.libwmf}
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/libwmf/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
