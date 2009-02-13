# $NetBSD: Makefile,v 1.23 2009/02/13 21:33:00 abs Exp $
#

DISTNAME=	if-psprint-1.9
CATEGORIES=	print
MASTER_SITES=	http://if-psprint.googlecode.com/files/
EXTRACT_SUFX=  	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/if-psprint/
COMMENT=	Print text or postscript to arbitrary printer, can use smb

DEPENDS+=	enscript>=1.6.3nb1:../../print/enscript

REPLACE_PERL=	if-psprint.pl
USE_TOOLS+=	gs:run perl:run
PKG_DESTDIR_SUPPORT = user-destdir

.include "../../mk/bsd.pkg.mk"
