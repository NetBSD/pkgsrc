# $NetBSD: Makefile,v 1.11 2008/02/06 07:17:00 bjs Exp $

DISTNAME=		duplicity-0.4.9
CATEGORIES=		sysutils net
MASTER_SITES=		http://savannah.nongnu.org/download/duplicity/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/duplicity/
COMMENT=		Remote encrypting incremental backup utility

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.librsync+=	librsync>=0.9.6
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24

.include "../../devel/py-pexpect/buildlink3.mk"
.include "../../devel/librsync/buildlink3.mk"
.include "../../net/py-boto/buildlink3.mk"
.include "../../security/py-gnupg/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
