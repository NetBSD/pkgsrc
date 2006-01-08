# $NetBSD: Makefile,v 1.5 2006/01/08 20:40:02 joerg Exp $

DISTNAME=	gcc-3.3.5
PKGNAME=	libffi-2.0beta
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-3.3.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sources.redhat.com/libffi/
COMMENT=	Foreign function interface

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	with_target_subdir=.
CONFIG_GUESS_OVERRIDE=	../config.guess
CONFIG_SUB_OVERRIDE=	../config.sub

WRKSRC=		${WRKDIR}/${DISTNAME}/libffi

.include "../../mk/bsd.pkg.mk"
