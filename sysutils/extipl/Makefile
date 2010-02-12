# $NetBSD: Makefile,v 1.10 2010/02/12 14:56:19 joerg Exp $
#

DISTNAME=	extipl-5.04
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tsden.org/takamiti/extipl/archs/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.tsden.org/takamiti/extipl/
COMMENT=	IPL compatible OS boot selector

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
