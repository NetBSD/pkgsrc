# $NetBSD: Makefile,v 1.18 2006/01/23 14:23:56 salo Exp $
#

DISTNAME=	antiword-0.37
PKGREVISION=	1
CATEGORIES=	textproc converters print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	Free MS Word to text and PostScript converter

CONFLICTS=	siag-[0-9]*

USE_TOOLS+=	mktemp:run

CFLAGS.SunOS+=	-D__STDC_ISO_10646__

post-patch:
	cd ${WRKSRC} ; \
	for pf in antiword.h Docs/antiword.1 ; do \
	  ${MV} $${pf} $${pf}.old ; \
	  ${SED} -e "s|/usr/share|${PREFIX}/share|g" $${pf}.old > $${pf} ; \
	done

.include "../../mk/bsd.pkg.mk"
