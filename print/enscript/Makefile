# $NetBSD: Makefile,v 1.18 2001/02/17 17:51:40 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

DEPENDS+=		papersize-*:../../print/papersize

GNU_CONFIGURE=		yes
.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media="${PAPERSIZE}"
.endif

.include "../../mk/bsd.pkg.mk"
