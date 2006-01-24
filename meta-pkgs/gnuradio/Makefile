# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:21 wiz Exp $

DISTNAME=	gnuradio-2.6
PKGREVISION=	1
CATEGORIES=	meta-pkgs ham gnuradio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnuradio/
COMMENT=	"meta-package" for GNU Radio

DEPENDS+=	gnuradio-core-2.6{,nb[0-9]*}:../../ham/gnuradio-core
DEPENDS+=	gnuradio-audio-oss-0.7{,nb[0-9]*}:../../ham/gnuradio-audio-oss
DEPENDS+=	gnuradio-gsm-0.2{,nb[0-9]*}:../../ham/gnuradio-gsm
DEPENDS+=	usrp-0.9{,nb[0-9]*}:../../ham/usrp
DEPENDS+=	gnuradio-usrp-0.6{,nb[0-9]*}:../../ham/gnuradio-usrp
DEPENDS+=	gnuradio-wxgui-0.4{,nb[0-9]*}:../../ham/gnuradio-wxgui
DEPENDS+=	gnuradio-examples-0.5{,nb[0-9]*}:../../ham/gnuradio-examples
DEPENDS+=	gnuradio-howto-0.4{,nb[0-9]*}:../../ham/gnuradio-howto

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
