# $NetBSD: Makefile,v 1.7 2004/12/03 15:15:04 wiz Exp $
# FreeBSD Id: ports/misc/bottlerocket/Makefile,v 1.4 2000/04/14 08:45:23 asami Exp

DISTNAME=	bottlerocket-0.04c
CATEGORIES=	misc
MASTER_SITES=	http://mlug.missouri.edu/~tymm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mlug.missouri.edu/~tymm/
COMMENT=	Home Automation Software for the X10 FireCracker kit

USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes
BUILD_TARGET=	br

X10_PORT?=	${DEFAULT_SERIAL_DEVICE}
CONFIGURE_ARGS+=--with-x10port=${X10_PORT}
BUILD_DEFS+=	X10_PORT

.include "../../mk/bsd.pkg.mk"
