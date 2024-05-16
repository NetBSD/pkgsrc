# $NetBSD: Makefile,v 1.14 2024/05/16 06:15:11 wiz Exp $
DISTNAME=	gkrellsun-1.0.0
PKGREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gkrellsun/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gkrellsun.sourceforge.net/
COMMENT=	GKrellM plugin to display sun rise and sun set times
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake

.include "options.mk"

INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} "${WRKSRC}/README" \
		"${DESTDIR}${PREFIX}/share/doc/${PKGBASE}"

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
