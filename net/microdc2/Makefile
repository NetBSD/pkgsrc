# $NetBSD: Makefile,v 1.3 2009/05/20 00:58:25 wiz Exp $
#

DISTNAME=	microdc2-0.15.6
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://corsair626.no-ip.org/microdc/

MAINTAINER=	d.den.brok@uni-bonn.de
HOMEPAGE=	http://corsair626.no-ip.org/microdc/
COMMENT=	Console-based DirectConnect client

PKG_DESTDIR_SUPPORT=		user-destdir

BUILDLINK_API_DEPENDS.readline+=readline>=4
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.16

GNU_CONFIGURE=		yes

USE_GNU_READLINE=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		ln msgfmt msgmerge

post-install:
	cd ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1 && \
		ln -s microdc.1 microdc2.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
