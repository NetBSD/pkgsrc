# $NetBSD: Makefile,v 1.1.1.1 2005/11/22 19:26:08 wiz Exp $
#

DISTNAME=		libmpd-0.01
CATEGORIES=		audio
MASTER_SITES=		http://download.qballcow.nl/programs/libmpd/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://download.qballcow.nl/programs/libmpd/libmpd.html
COMMENT=		Library to access mpd (musicpd)

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libmpd-0.01.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
