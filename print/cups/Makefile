# $NetBSD: Makefile,v 1.298 2025/10/23 20:38:58 wiz Exp $

PKGREVISION= 1
.include "../../print/cups/Makefile.common"

PKGNAME=	cups-${CUPS_VERS}
MASTER_SITES=	# empty

MAINTAINER=	sbd@NetBSD.org
COMMENT=	Common UNIX Printing System

META_PACKAGE=	yes

.include "../../print/cups-base/buildlink3.mk"
.include "../../print/cups-filters/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
