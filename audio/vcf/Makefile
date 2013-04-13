# $NetBSD: Makefile,v 1.1 2013/04/13 14:49:09 rodent Exp $
#

DISTNAME=	vcf-0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.suse.de/~mana/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.suse.de/~mana/ladspa.html
COMMENT=	Some LADSPA plugins for audio EQ biquad filters
LICENSE=	gnu-lgpl-v3

INSTALLATION_DIRS+=	lib/ladspa

do-install:
	${INSTALL_LIB} ${WRKSRC}/vcf.so ${DESTDIR}${BUILDLINK_PREFIX.ladspa}/lib/ladspa

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
