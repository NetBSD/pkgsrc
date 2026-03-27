# $NetBSD: Makefile,v 1.17 2026/03/27 21:27:47 tnn Exp $

DISTNAME=	extipl-5.04
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_OSDN:=extipl/2166/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
#HOMEPAGE=	http://osdn.jp/projects/extipl/
COMMENT=	IPL compatible OS boot selector
LICENSE=	gnu-gpl-v2

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

TOOL_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
