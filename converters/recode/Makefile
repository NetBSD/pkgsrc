# $NetBSD: Makefile,v 1.22 2006/02/05 23:08:29 joerg Exp $
#

DISTNAME=		recode-3.6
PKGREVISION=		3
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=recode/}

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/recode/recode.html
COMMENT=		Convert files between character sets and usages

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
BROKEN_GETTEXT_DETECTION=	yes

INFO_FILES=     	recode.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
