# $NetBSD: Makefile,v 1.12 2012/10/23 19:51:00 asau Exp $
#

DISTNAME=	extipl-5.04
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=extipl/2166/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://sourceforge.jp/projects/extipl/
COMMENT=	IPL compatible OS boot selector

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
