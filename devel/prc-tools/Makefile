# $NetBSD: Makefile,v 1.3 2001/06/27 05:07:33 jlam Exp $
#

.include "Makefile.common"

COMMENT=	GNU tool chain for Palm cross development

MASTER_SITES=   # empty
DISTFILES=      # empty

DEPENDS+=	prc-tools-base>=2.0:../../devel/prc-tools-base
DEPENDS+=	prc-tools-gdb>=2.0:../../devel/prc-tools-gdb
DEPENDS+=	pilrc>=2.7:../../devel/pilrc

EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_PATCH=       yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:     # empty

.include "../../mk/bsd.pkg.mk"
