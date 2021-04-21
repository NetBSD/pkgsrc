# $NetBSD: Makefile,v 1.274 2021/04/21 13:25:15 adam Exp $

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
