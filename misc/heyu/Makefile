# $NetBSD: Makefile,v 1.10 2004/02/02 21:07:26 abs Exp $
#

DISTNAME=	x10_heyu
PKGNAME=	heyu-1.35
CATEGORIES=	misc
MASTER_SITES=	http://heyu.tanj.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://heyu.tanj.com/
COMMENT=	Home Automation Software for the X10 CM11A

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/heyu.dir

CONFIGURE_SCRIPT=	./Configure
MAKE_ENV+=	DEFAULT_SERIAL_DEVICE=${DEFAULT_SERIAL_DEVICE}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/heyu

.include "../../mk/bsd.pkg.mk"
