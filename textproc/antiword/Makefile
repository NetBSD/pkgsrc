# $NetBSD: Makefile,v 1.14 2004/11/23 18:20:03 wiz Exp $
#

DISTNAME=	antiword-0.36
CATEGORIES=	textproc converters print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	Free MS Word to text and PostScript converter

CONFLICTS=	siag-[0-9]*

post-patch:
	cd ${WRKSRC} ; \
	for pf in antiword.h Docs/antiword.1 ; do \
	  ${MV} $${pf} $${pf}.old ; \
	  ${SED} -e "s|/usr/share|${PREFIX}/share|g" $${pf}.old > $${pf} ; \
	done

.include "../../mk/bsd.pkg.mk"
