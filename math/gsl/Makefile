# $NetBSD: Makefile,v 1.4 2001/05/23 20:24:05 jtb Exp $
#

DISTNAME=	gsl-0.8
CATEGORIES=	math devel
MASTER_SITES=	ftp://sources.redhat.com/pub/gsl/ \
		ftp://ftp.freesoftware.com/pub/sourceware/pub/gsl/ \
		ftp://mirrors.rcn.net/pub/sourceware/pub/gsl/ \
		ftp://gd.tuwien.ac.at/gnu/sourceware/gsl/ \
		ftp://ftp.funet.fi/pub/mirrors/sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp.unina.it/pub/Unix/cygnus/gsl/ \
		ftp://ftp.pvv.ntnu.no/pub/cygnus/sourceware.cygnus.com/gsl/ \
		ftp://ftp.fic.uni.lodz.pl/pub/sources.redhat.com/pub/gsl/ \
		ftp://ftp.chg.ru/pub/sourceware/gsl/ \
		ftp://ftp.sun.ac.za/sites/sourceware.cygnus.com/pub/gsl/ \
		ftp://ftp1.sinica.edu.tw/pub3/CYGNUS/gsl/ \
		ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/gsl/ \
		ftp://unix.hensa.ac.uk/mirrors/sourceware.cygnus.com/pub/gsl/

MAINTAINER=	David Maxwell <david@maxwell.net>
HOMEPAGE=	http://sources.redhat.com/gsl/
COMMENT=	The GNU Scientific Library - mathematical libs

GNU_CONFIGURE=		yes
USE_GTEXINFO=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
