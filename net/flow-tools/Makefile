# $NetBSD: Makefile,v 1.2 2002/10/10 11:49:40 wiz Exp $

DISTNAME=	flow-tools-0.59
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.splintered.net/sw/flow-tools/
COMMENT=	Collect and store NetFlow data

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
