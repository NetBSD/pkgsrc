# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:14 tv Exp $
#

DISTNAME=		duplicity-0.4.1
PKGREVISION=	1
CATEGORIES=		sysutils net
MASTER_SITES=		http://savannah.nongnu.org/download/duplicity/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/duplicity/
COMMENT=		Remote encrypting incremental backup utility

DEPENDS=		gnupg>=1.2.3:../../security/gnupg

BUILDLINK_DEPENDS.librsync=	librsync>=0.9.6
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 22pth 23pth
USE_BUILDLINK3=		yes

.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
