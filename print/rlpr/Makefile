# $NetBSD: Makefile,v 1.2 2005/03/24 17:12:17 tv Exp $

DISTNAME=		rlpr-2.06
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		ftp://truffula.com/pub/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://truffula.com/rlpr
COMMENT=		lpr work-alike to print directly to remote printer

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
