# $NetBSD: Makefile,v 1.41 2003/10/31 16:42:53 gavan Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-1.1.2
CATEGORIES=	converters kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Mime library for the KDE integrated X11 desktop

USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes
USE_GCC_SHLIB=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib" \
		"--without-sprite-field"

.include "../../mk/bsd.pkg.mk"
