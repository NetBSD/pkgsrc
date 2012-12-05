# $NetBSD: Makefile,v 1.2 2012/12/05 22:52:16 dsainty Exp $
#

DISTNAME=	lirc-0.9.0
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lirc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.lirc.org/
COMMENT=	Linux Infrared Remote Control
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-syslog --with-driver=userspace
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

RCD_SCRIPTS=		lircd

EGDIR=			${PREFIX}/share/examples/lirc
EGFILES=		lircd.conf lircmd.conf

INSTALLATION_DIRS=	${EGDIR}

post-install:
.for i in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/contrib/${i} ${DESTDIR}${EGDIR}
.endfor

.include "available.mk"
.if ${LIRC_AVAILABLE} == no
PKG_FAIL_REASON=	"lirc is not available for this platform"
.endif

.include "options.mk"

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
