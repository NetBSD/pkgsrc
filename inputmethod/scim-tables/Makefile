# $NetBSD: Makefile,v 1.38 2018/11/14 22:21:53 kleink Exp $
#

DISTNAME=		scim-tables-0.5.14.1
PKGREVISION=		9
CATEGORIES=		inputmethod
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scim-im.org/
COMMENT=		Data files for SCIM Generic Table Input Method module
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake automake autoconf
GNU_CONFIGURE=		yes

USE_SCIM_GTKUTILS=	yes

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

pre-configure:
	${RUN}cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${SH} bootstrap

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
