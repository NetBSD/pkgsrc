# New ports collection makefile for:   kdesupport
# Version required:    Beta2
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $NetBSD: Makefile,v 1.3 1998/01/24 03:38:26 hubertf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-Beta2-1
PKGNAME=	kdesupport-2.1b
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta2/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta2/distribution/tgz/source/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	se@freebsd.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${X11BASE}/include -I${PREFIX}/include -I${PREFIX}/include/giflib" \
		"--x-lib=${X11BASE}/lib -L${PREFIX}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm"

WRKSRC=		${WRKDIR}/kdesupport

.include <bsd.port.mk>
