# $NetBSD: Makefile,v 1.8 2003/11/11 10:17:39 wiz Exp $
#

DISTNAME=	x10_heyu
PKGNAME=	x10_heyu-1.35
WRKSRC=		${WRKDIR}/heyu.dir
CATEGORIES=	misc
MASTER_SITES=	http://heyu.tanj.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://heyu.tanj.com/
COMMENT=	Home Automation Software for the X10 CM11A

DIST_SUBDIR=	${PKGNAME_NOREV}

CONFIGURE_SCRIPT=	./Configure
MAKE_ENV+=	DEFAULT_SERIAL_DEVICE=${DEFAULT_SERIAL_DEVICE}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/heyu

.include "../../mk/bsd.pkg.mk"
