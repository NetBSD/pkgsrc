# $NetBSD: Makefile,v 1.17 2000/01/11 19:31:00 hubertf Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/

DEPENDS+=		papersize-*:../../print/papersize

GNU_CONFIGURE=		yes
.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media="${PAPERSIZE}"
.endif

.include "../../mk/bsd.pkg.mk"
