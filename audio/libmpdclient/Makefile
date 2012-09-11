# $NetBSD: Makefile,v 1.5 2012/09/12 00:24:43 asau Exp $
#

DISTNAME=	libmpdclient-2.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpd.wikia.com/wiki/ClientLib:libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmpdclient.pc.in

CONFIGURE_ENV+=		ac_cv_path_DOXYGEN=

.include "../../mk/bsd.pkg.mk"
