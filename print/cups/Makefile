# $NetBSD: Makefile,v 1.293 2025/04/19 07:58:16 wiz Exp $

PKGREVISION= 5
.include "../../print/cups/Makefile.common"

PKGNAME=	cups-${CUPS_VERS}
MASTER_SITES=	# empty

MAINTAINER=	sbd@NetBSD.org
COMMENT=	Common UNIX Printing System

META_PACKAGE=	yes

.include "../../print/cups-base/buildlink3.mk"
.include "../../print/cups-filters/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
