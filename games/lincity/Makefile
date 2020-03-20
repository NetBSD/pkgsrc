# $NetBSD: Makefile,v 1.30 2020/03/20 11:57:42 nia Exp $

DISTNAME=	lincity-1.12.1
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lincity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lincity.sourceforge.net/
COMMENT=	Free clone of SimCity for X11
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CHECK_INTERPRETER_SKIP+=	share/lincity/icons/*

INSTALLATION_DIRS+=	share/lincity/help share/lincity/icons \
			share/lincity/messages share/lincity/opening

post-install:
	${LN} -sf lincity.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xlincity.6

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
