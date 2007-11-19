# $NetBSD: Makefile,v 1.10 2007/11/19 13:46:36 tron Exp $

DISTNAME=		duplicity-0.4.3
CATEGORIES=		sysutils net
MASTER_SITES=		http://savannah.nongnu.org/download/duplicity/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/duplicity/
COMMENT=		Remote encrypting incremental backup utility

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

.include "../../devel/py-pexpect/buildlink3.mk"
.include "../../devel/librsync/buildlink3.mk"
.include "../../security/py-gnupg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
