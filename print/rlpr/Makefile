# $NetBSD: Makefile,v 1.8 2010/02/12 00:08:02 joerg Exp $

DISTNAME=		rlpr-2.06
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		ftp://truffula.com/pub/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://truffula.com/rlpr/
COMMENT=		lpr work-alike to print directly to remote printer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
