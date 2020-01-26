# $NetBSD: Makefile,v 1.17 2020/01/26 17:31:42 rillig Exp $

DISTNAME=	bottlerocket-0.04c
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://mlug.missouri.edu/~tymm/
MASTER_SITES=	http://www.linuxha.com/bottlerocket/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.linuxha.com/bottlerocket/
COMMENT=	Home Automation Software for the X10 FireCracker kit

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
BUILD_TARGET=	br

X10_PORT?=		${DEFAULT_SERIAL_DEVICE}
CONFIGURE_ARGS+=	--with-x10port=${X10_PORT:Q}
BUILD_DEFS+=		X10_PORT

.include "../../mk/bsd.pkg.mk"
