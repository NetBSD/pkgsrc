# $NetBSD: Makefile,v 1.6 2004/01/20 12:26:15 agc Exp $
#

DISTNAME=	extipl-5.04
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tsden.org/takamiti/extipl/archs/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.tsden.org/takamiti/extipl/
COMMENT=	IPL compatible OS boot selector

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_GMAKE=	#defined

.include "../../mk/bsd.pkg.mk"
