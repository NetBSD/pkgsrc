# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 16:09:21 xtraeme Exp $
#

DISTNAME=	xfe-0.54.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xfe/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://xfe.sourceforge.net/
COMMENT=	Fast MS-Explorer like filemanager for X

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes

PKG_SYSCONFSUBDIR=	xfe
EGDIR=			${PREFIX}/share/examples/xfe
CONF_FILES=		${EGDIR}/Desktop ${PKG_SYSCONFDIR}/Desktop

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/Desktop ${EGDIR}

.include "../../x11/fox/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
