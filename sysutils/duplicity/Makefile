# $NetBSD: Makefile,v 1.9 2006/10/08 13:42:21 obache Exp $
#

DISTNAME=		duplicity-0.4.2
CATEGORIES=		sysutils net
MASTER_SITES=		http://savannah.nongnu.org/download/duplicity/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/duplicity/
COMMENT=		Remote encrypting incremental backup utility

DEPENDS+=		gnupg>=1.2.3:../../security/gnupg

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 22 23 24

.include "../../devel/librsync/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
