# $NetBSD: Makefile,v 1.13 1999/04/14 21:39:04 tron Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/

DEPENDS+=		papersize-1.0:../../print/papersize

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
