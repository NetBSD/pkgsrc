# $NetBSD: Makefile,v 1.31 2015/06/12 10:50:58 wiz Exp $
#

DISTNAME=	if-psprint-1.10
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	http://if-psprint.googlecode.com/files/
EXTRACT_SUFX=  	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/if-psprint/
COMMENT=	Print text or postscript to arbitrary printer, can use smb

DEPENDS+=	enscript>=1.6.3nb1:../../print/enscript

REPLACE_PERL=	if-psprint.pl
USE_TOOLS+=	gs:run perl:run pod2man

.include "../../mk/bsd.pkg.mk"
