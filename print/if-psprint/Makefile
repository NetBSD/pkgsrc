# $NetBSD: Makefile,v 1.33 2016/07/09 06:38:51 wiz Exp $
#

DISTNAME=	if-psprint-1.10
PKGREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://if-psprint.googlecode.com/files/
EXTRACT_SUFX=  	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/if-psprint/
COMMENT=	Print text or postscript to arbitrary printer, can use smb

DEPENDS+=	enscript>=1.6.3nb1:../../print/enscript

REPLACE_PERL=	if-psprint.pl
USE_TOOLS+=	gs:run perl:run pod2man

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,man/,${PKGMANDIR}/,g'

.include "../../mk/bsd.pkg.mk"
