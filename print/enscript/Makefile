# $NetBSD: Makefile,v 1.21 2003/04/27 14:46:15 cjep Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

DEPENDS+=		papersize-[0-9]*:../../print/papersize

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media="${PAPERSIZE}"
.endif

.include "../../mk/bsd.pkg.mk"
