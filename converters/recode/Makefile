# $NetBSD: Makefile,v 1.27 2009/03/25 06:08:16 yyamano Exp $
#

DISTNAME=		recode-3.6
PKGREVISION=		4
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=recode/}

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/recode/recode.html
COMMENT=		Convert files between character sets and usages

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
BROKEN_GETTEXT_DETECTION=	yes

INFO_FILES=	# PLIST

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
