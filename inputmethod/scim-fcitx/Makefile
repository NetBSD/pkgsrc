# $NetBSD: Makefile,v 1.7 2011/11/01 06:01:54 sbd Exp $
#

DISTNAME=		scim-fcitx.3.1.1
PKGNAME=		scim-fcitx-3.1.1
PKGREVISION=		6
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Fcitx ported to SCIM
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		fcitx-[0-9]*

WRKSRC=			${WRKDIR}/fcitx

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

MAKE_JOBS_SAFE=		no

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
