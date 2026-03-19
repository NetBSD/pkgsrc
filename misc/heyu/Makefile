# $NetBSD: Makefile,v 1.18 2026/03/19 14:55:20 nia Exp $
#

DISTNAME=	heyu-1.35
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://heyu.tanj.com/
DISTFILES=	x10_heyu.tgz

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	https://www.heyu.org/
COMMENT=	Home Automation Software for the X10 CM11A

PKG_DESTDIR_SUPPORT=	destdir

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/heyu.dir

CONFIGURE_SCRIPT=	./Configure
MAKE_ENV+=		DEFAULT_SERIAL_DEVICE=${DEFAULT_SERIAL_DEVICE:Q}
INSTALL_MAKE_FLAGS+=	BIN=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	MAN5=${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

FORCE_C_STD=	gnu89

REPLACE_SH+=	makesched
USE_TOOLS+=	sh:run

INSTALLATION_DIRS+=	bin share/examples/heyu

.include "../../mk/bsd.pkg.mk"
