# $NetBSD: Makefile,v 1.1.1.1 2009/09/22 17:42:40 taca Exp $
#
DISTNAME=		${FP_DISTNAME}
CATEGORIES=		security

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/corporate_users/unix/
COMMENT=		F-PROT antivirus for workstations

PKG_DESTDIR_SUPPORT=	user-destdir
USE_TOOLS+=		pax

FP_TYPE=		ws

do-install: install-common

.include "../../security/f-prot-antivirus6/Makefile.common"
.include "../../mk/bsd.pkg.mk"
