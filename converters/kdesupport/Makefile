# $NetBSD: Makefile,v 1.36 2000/11/08 15:09:36 abs Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-1.1.2
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/Attic/old/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/

USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib" \
		"--without-sprite-field"

.include "../../mk/bsd.pkg.mk"
