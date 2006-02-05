# $NetBSD: Makefile,v 1.15 2006/02/05 23:10:58 joerg Exp $

DISTNAME=	xfe-0.84
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xfe.sourceforge.net/
COMMENT=	Fast MS-Explorer like filemanager for X

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	xfe
EGDIR=			${PREFIX}/share/examples/xfe
CONF_FILES=		${EGDIR}/Desktop ${PKG_SYSCONFDIR}/Desktop

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/Desktop ${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/fox/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
