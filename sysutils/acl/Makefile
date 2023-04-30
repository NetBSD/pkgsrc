# $NetBSD: Makefile,v 1.2 2023/04/30 20:14:39 gdt Exp $

DISTNAME=	acl-2.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.savannah.nongnu.org/releases/acl/

MAINTAINER=	als@thangorodrim.ch
HOMEPAGE=	https://savannah.nongnu.org/projects/acl
COMMENT=	Provides missing POSIX ACL interfaces for Linux
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

USE_LIBTOOL=	yes

.include "../../sysutils/attr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
