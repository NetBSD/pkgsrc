# $NetBSD: Makefile,v 1.253 2017/11/23 17:20:09 wiz Exp $

.include "../../print/cups/Makefile.common"

PKGNAME=	cups-${CUPS_VERS}
PKGREVISION=	2
MASTER_SITES=	# empty

MAINTAINER=	sbd@NetBSD.org
COMMENT=	Common UNIX Printing System

META_PACKAGE=	yes

.include "../../print/cups-base/buildlink3.mk"
.include "../../print/cups-filters/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
