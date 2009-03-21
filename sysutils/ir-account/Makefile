# $NetBSD: Makefile,v 1.4 2009/03/21 11:58:56 gdt Exp $
#

DISTNAME=		ir-account-0.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ir.bbn.com/~gdt/ir-account/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.ir.bbn.com/~gdt/ir-account/
COMMENT=		Copy accounts among systems and manage sudo privs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=		sudo>=1.6:../../security/sudo

.include "../../mk/bsd.pkg.mk"
