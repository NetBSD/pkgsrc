# $NetBSD: Makefile,v 1.25 2013/10/10 14:42:19 ryoon Exp $
#

DISTNAME=		scim-tables-0.5.13
PKGREVISION=		5
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Data files for SCIM Generic Table Input Method module
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
