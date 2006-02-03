# $NetBSD: Makefile,v 1.2 2006/02/03 21:03:43 gdt Exp $
#

DISTNAME=		ir-account-0.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ir.bbn.com/~gdt/ir-account/

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://www.ir.bbn.com/~gdt/ir-account/
COMMENT=		Copy accounts among systems and manage sudo privs

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=		sudo>=1.6:../../security/sudo

.include "../../mk/bsd.pkg.mk"
