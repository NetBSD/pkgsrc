# $NetBSD: Makefile,v 1.17 2003/08/09 10:35:48 seb Exp $
#

DISTNAME=		recode-3.6
PKGREVISION=		1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=recode/}

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/recode/recode.html
COMMENT=		Convert files between character sets and usages

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INFO_FILES=     	recode.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
