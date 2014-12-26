# $NetBSD: Makefile,v 1.15 2014/12/26 23:43:52 mef Exp $

DISTNAME=	bottlerocket-0.04c
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://mlug.missouri.edu/~tymm/
MASTER_SITES=	http://www.linuxha.com/bottlerocket/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxha.com/bottlerocket/
COMMENT=	Home Automation Software for the X10 FireCracker kit

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
BUILD_TARGET=	br

X10_PORT?=	${DEFAULT_SERIAL_DEVICE}
CONFIGURE_ARGS+=--with-x10port=${X10_PORT:Q}
BUILD_DEFS+=	X10_PORT

.include "../../mk/bsd.pkg.mk"
