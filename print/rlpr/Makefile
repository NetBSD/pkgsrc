# $NetBSD: Makefile,v 1.4 2006/01/02 15:15:22 joerg Exp $

DISTNAME=		rlpr-2.06
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		ftp://truffula.com/pub/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://truffula.com/rlpr
COMMENT=		lpr work-alike to print directly to remote printer

GNU_CONFIGURE=		YES
BROKEN_GETTEXT_DETECTION=	no

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
