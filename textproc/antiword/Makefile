# $NetBSD: Makefile,v 1.15 2005/01/01 03:57:21 wiz Exp $
#

DISTNAME=	antiword-0.36.1
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
