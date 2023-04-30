# $NetBSD: Makefile,v 1.3 2023/04/30 20:16:54 gdt Exp $

DISTNAME=	acl-2.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.nongnu.org/releases/acl/

MAINTAINER=	als@thangorodrim.ch
HOMEPAGE=	https://savannah.nongnu.org/projects/acl
COMMENT=	Provides missing POSIX ACL interfaces for Linux
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

# The point of this package is to provide POSIX facilities that are
# missing on Linux.  In addition to not being portable to other
# systems, it is not useful on other systems because systems that have
# ACLs provide the interfaces already.
ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

USE_LIBTOOL=	yes

.include "../../sysutils/attr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
