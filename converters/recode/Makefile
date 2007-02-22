# $NetBSD: Makefile,v 1.25 2007/02/22 19:26:15 wiz Exp $
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
BROKEN_GETTEXT_DETECTION=	yes

INFO_FILES=	# PLIST

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
