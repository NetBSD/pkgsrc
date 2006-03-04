# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:44 jlam Exp $

DISTNAME=	xfe-0.84
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
