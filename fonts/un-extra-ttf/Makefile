# $NetBSD: Makefile,v 1.12 2020/11/06 18:04:27 maya Exp $

DISTNAME=	un-fonts-extra-1.0.2-080608
PKGNAME=	${DISTNAME:S/fonts-extra/extra-ttf/:S/-0/.200/}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/frs/download.php/4696/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	https://kldp.net/projects/unfonts/
COMMENT=	Extra set of Un Korean TrueType fonts

CONFLICTS+=	un-ttf-[0-9]*

WRKSRC=		${WRKDIR}/un-fonts

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
