# $NetBSD: Makefile,v 1.6 2001/11/22 12:58:40 agc Exp $
#

DISTNAME=	gsl-1.0
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
COMMENT=	The GNU Scientific Library

GNU_CONFIGURE=		yes
USE_GTEXINFO=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
