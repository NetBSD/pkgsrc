# $NetBSD: Makefile,v 1.11 2024/05/29 16:32:00 adam Exp $

DISTNAME=	dumpet-2.1
PKGREVISION=	9
CATEGORIES=	devel
#MASTER_SITES=	https://fedorahosted.org/releases/d/u/dumpet/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://github.com/rhboot/dumpet/
COMMENT=	Dump information about bootable CDs and other similar formats
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
