# $NetBSD: Makefile,v 1.2 2003/12/24 09:53:48 jmmv Exp $

DISTNAME=	gcc-3.3
PKGNAME=	libffi-2.0beta
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sources.redhat.com/libffi/
COMMENT=	Foreign function interface

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	with_target_subdir=.

WRKSRC=		${WRKDIR}/${DISTNAME}/libffi

.include "../../mk/bsd.pkg.mk"
