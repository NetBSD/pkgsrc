# $NetBSD: Makefile,v 1.2 2001/10/11 10:02:04 agc Exp $
#

DISTNAME=	extipl-5.03
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tsden.org/takamiti/extipl/archs/

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://www.tsden.org/takamiti/extipl/
COMMENT=	IPL compatible OS boot selector

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/extipl-5.03/src
USE_GMAKE=	#defined

.include "../../mk/bsd.pkg.mk"
