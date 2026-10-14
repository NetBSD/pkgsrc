#	$NetBSD: Makefile,v 1.1 2026/10/14 03:34:55 riastradh Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:C/^dkim-rotate-dkim-rotate-/dkim-rotate-/}

COMMENT=	Tool and documentation for rotation and revocation of DKIM keys

DEPENDS+=	dkim-rotate-base>=${PKGVERSION}:../../mail/dkim-rotate-base
DEPENDS+=	dkim-rotate-doc>=${PKGVERSION}:../../mail/dkim-rotate-doc

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
