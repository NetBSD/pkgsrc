# $NetBSD: Makefile,v 1.8 2005/03/24 21:12:57 wiz Exp $

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
