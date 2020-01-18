# $NetBSD: Makefile,v 1.11 2020/01/18 23:31:58 rillig Exp $

DISTNAME=	un-fonts-core-1.0.2-080608
PKGNAME=	${DISTNAME:S/fonts-core/core-ttf/:S/-0/.200/}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/frs/download.php/4695/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	https://kldp.net/projects/unfonts/
COMMENT=	Core set of Un Korean TrueType fonts

CONFLICTS+=	un-ttf-[0-9]*

WRKSRC=		${WRKDIR}/un-fonts

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
