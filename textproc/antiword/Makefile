# $NetBSD: Makefile,v 1.17 2005/11/14 23:04:13 wiz Exp $
#

DISTNAME=	antiword-0.37
CATEGORIES=	textproc converters print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	Free MS Word to text and PostScript converter

CONFLICTS=	siag-[0-9]*

CFLAGS.SunOS+=	-D__STDC_ISO_10646__

post-patch:
	cd ${WRKSRC} ; \
	for pf in antiword.h Docs/antiword.1 ; do \
	  ${MV} $${pf} $${pf}.old ; \
	  ${SED} -e "s|/usr/share|${PREFIX}/share|g" $${pf}.old > $${pf} ; \
	done

.include "../../mk/bsd.pkg.mk"
