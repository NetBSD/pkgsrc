# $NetBSD: Makefile,v 1.256 2018/03/12 11:17:25 wiz Exp $

PKGREVISION= 2
.include "../../print/cups/Makefile.common"

PKGNAME=	cups-${CUPS_VERS}
MASTER_SITES=	# empty

MAINTAINER=	sbd@NetBSD.org
COMMENT=	Common UNIX Printing System

META_PACKAGE=	yes

.include "../../print/cups-base/buildlink3.mk"
.include "../../print/cups-filters/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
