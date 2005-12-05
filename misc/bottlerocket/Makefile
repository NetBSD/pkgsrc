# $NetBSD: Makefile,v 1.10 2005/12/05 23:55:12 rillig Exp $

DISTNAME=	bottlerocket-0.04c
CATEGORIES=	misc
MASTER_SITES=	http://mlug.missouri.edu/~tymm/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mlug.missouri.edu/~tymm/
COMMENT=	Home Automation Software for the X10 FireCracker kit

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
BUILD_TARGET=	br

X10_PORT?=	${DEFAULT_SERIAL_DEVICE}
CONFIGURE_ARGS+=--with-x10port=${X10_PORT:Q}
BUILD_DEFS+=	X10_PORT

.include "../../mk/bsd.pkg.mk"
