# $NetBSD: Makefile,v 1.6 2003/10/25 16:48:03 kristerw Exp $
#

DISTNAME=	x10_heyu
PKGNAME=	x10_heyu-1.33
WRKSRC=		${WRKDIR}/heyu.dir
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_BACKUP}
# MASTER_SITES=	http://heyu.tanj.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://heyu.tanj.com/
COMMENT=	Home Automation Software for the X10 CM11A

DIST_SUBDIR=	${PKGNAME}

CONFIGURE_SCRIPT=	./Configure
MAKE_ENV+=	DEFAULT_SERIAL_DEVICE=${DEFAULT_SERIAL_DEVICE}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/heyu

.include "../../mk/bsd.pkg.mk"
