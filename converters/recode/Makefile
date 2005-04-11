# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:09 tv Exp $
#

DISTNAME=		recode-3.6
PKGREVISION=		2
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=recode/}

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/recode/recode.html
COMMENT=		Convert files between character sets and usages

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INFO_FILES=     	recode.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
