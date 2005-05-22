# $NetBSD: Makefile,v 1.8 2005/05/22 20:08:32 jlam Exp $
#

DISTNAME=	extipl-5.04
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tsden.org/takamiti/extipl/archs/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.tsden.org/takamiti/extipl/
COMMENT=	IPL compatible OS boot selector

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
