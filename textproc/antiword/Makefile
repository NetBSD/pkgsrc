# $NetBSD: Makefile,v 1.10 2003/03/20 02:06:41 salo Exp $
#

DISTNAME=	antiword-0.33
CATEGORIES=	textproc converters print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	free MS Word to text and PostScript converter

CONFLICTS=	siag-[0-9]*

post-patch:
	cd ${WRKSRC} ; \
	for pf in antiword.h Docs/antiword.1 ; do \
	  ${MV} $${pf} $${pf}.old ; \
	  ${SED} -e "s|/usr/share|${PREFIX}/share|g" $${pf}.old > $${pf} ; \
	done

.include "../../mk/bsd.pkg.mk"
