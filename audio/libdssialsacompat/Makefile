# $NetBSD: Makefile,v 1.2 2022/07/25 11:12:19 wiz Exp $

DISTNAME=	libdssialsacompat-1.0.8a
CATEGORIES=	audio
MASTER_SITES=	http://smbolton.com/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://smbolton.com/linux.html
COMMENT=	Alsa compatibility library to build DSSI
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALLATION_DIRS=	include/dssi/alsa/sound
PKGCONFIG_OVERRIDE+=	libdssialsacompat.pc.in

.include "../../mk/bsd.pkg.mk"
