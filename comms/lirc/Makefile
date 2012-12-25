# $NetBSD: Makefile,v 1.3 2012/12/25 11:41:25 cheusov Exp $
#

DISTNAME=	lirc-0.9.0
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lirc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.lirc.org/
COMMENT=	Linux Infrared Remote Control
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-syslog --with-driver=userspace
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# I don't want to see python in dependencies but
# make pronto2lirc script usable if python is installed
CONFIGURE_ENV+=			ac_cv_path_PYTHON=${PREFIX}/bin/python
CHECK_INTERPRETER_SKIP+=	bin/pronto2lirc

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
