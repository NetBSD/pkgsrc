# $NetBSD: Makefile,v 1.12 2005/06/01 18:03:23 jlam Exp $
#

DISTNAME=	xfe-0.54.2
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xfe.sourceforge.net/
COMMENT=	Fast MS-Explorer like filemanager for X

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes

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
