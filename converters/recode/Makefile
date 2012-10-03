# $NetBSD: Makefile,v 1.31 2012/10/03 00:20:16 asau Exp $
#

DISTNAME=		recode-3.6
PKGREVISION=		6
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=recode/}

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/recode/recode.html
COMMENT=		Convert files between character sets and usages
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
BROKEN_GETTEXT_DETECTION=	yes

INFO_FILES=		yes

post-extract:
	${CP} ${WRKSRC}/lib/error.c ${WRKSRC}/src/error.c

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
