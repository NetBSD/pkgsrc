# $NetBSD: Makefile,v 1.15 2019/08/11 13:23:07 wiz Exp $
#

DISTNAME=	dmassage-0.6
PKGREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sentia.org/projects/dmassage/
COMMENT=	Parser for dmesg(8)

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

NO_BUILD=	yes
USE_TOOLS+=	perl:run
REPLACE_PERL=	dmassage

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dmassage ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
