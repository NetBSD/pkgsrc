# $NetBSD: Makefile,v 1.2 2012/10/23 18:16:26 asau Exp $
#
DISTNAME=		${FP_DISTNAME}
CATEGORIES=		security

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/corporate_users/unix/
COMMENT=		F-PROT antivirus for File Servers

USE_TOOLS+=		pax

FP_TYPE=		fs

RCD_SCRIPTS=		fpscand

do-install: install-common install-fpscand

.include "../../security/f-prot-antivirus6/Makefile.common"
.include "../../mk/bsd.pkg.mk"
