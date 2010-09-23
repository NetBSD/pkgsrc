# $NetBSD: Makefile,v 1.11 2010/09/23 07:39:26 taca Exp $
#

DISTNAME=	extipl-5.04
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=extipl/2166/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://sourceforge.jp/projects/extipl/
COMMENT=	IPL compatible OS boot selector

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
