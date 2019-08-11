# $NetBSD: Makefile,v 1.22 2019/08/11 13:23:07 wiz Exp $
#

DISTNAME=		etcmanage-0.9.4
PKGREVISION=		4
CATEGORIES=		sysutils
#MASTER_SITES=		http://www.ir.bbn.com/~gdt/etcmanage/

MAINTAINER=		gdt@NetBSD.org
#HOMEPAGE=		http://www.ir.bbn.com/~gdt/etcmanage/
COMMENT=		Automatically manage files in /etc
LICENSE=		modified-bsd

USE_TOOLS+=		perl:run
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

AUTO_MKDIRS=		YES
post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
