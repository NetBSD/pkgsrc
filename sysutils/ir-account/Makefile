# $NetBSD: Makefile,v 1.3 2008/07/14 12:56:12 joerg Exp $
#

DISTNAME=		ir-account-0.1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ir.bbn.com/~gdt/ir-account/

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://www.ir.bbn.com/~gdt/ir-account/
COMMENT=		Copy accounts among systems and manage sudo privs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

DEPENDS+=		sudo>=1.6:../../security/sudo

.include "../../mk/bsd.pkg.mk"
