# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:17 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-Beta3-1
PKGNAME=	kdesupport-3.1b
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	se@freebsd.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${X11BASE}/include -I${PREFIX}/include -I${PREFIX}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${PREFIX}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-includes=${X11BASE}/include/qt" \
		"--with-qt-libraries=${X11BASE}/lib" \
		"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib"

WRKSRC=		${WRKDIR}/kdesupport

.include "../../mk/bsd.pkg.mk"
