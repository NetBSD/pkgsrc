# $NetBSD: Makefile,v 1.29 2011/08/26 08:13:44 wiz Exp $
#

DISTNAME=		recode-3.6
PKGREVISION=		5
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=recode/}

MAINTAINER=		kleink@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/recode/recode.html
COMMENT=		Convert files between character sets and usages
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
BROKEN_GETTEXT_DETECTION=	yes

INFO_FILES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
