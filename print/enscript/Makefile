# $NetBSD: Makefile,v 1.19 2001/09/27 23:18:36 jlam Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

DEPENDS+=		papersize-[0-9]*:../../print/papersize

GNU_CONFIGURE=		yes
.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media="${PAPERSIZE}"
.endif

.include "../../mk/bsd.pkg.mk"
