# $NetBSD: Makefile,v 1.9 1998/11/09 18:06:19 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/

CONFLICTS=		enscript-Letter-1.6.0 enscript-A4-1.6.0 \
			enscript-Letterdj-1.6.0
CONFLICTS+=		enscript-Letter-1.6.1 enscript-A4-1.6.1 \
			enscript-Letterdj-1.6.1

DEPENDS+=		papersize-1.0:../../print/papersize

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ENV=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=		-static

post-install:
.for file in enscript mkafmmap states
	strip ${PREFIX}/bin/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
