# $NetBSD: Makefile,v 1.5 2023/12/29 01:07:02 zafer Exp $
#

DISTNAME=	vcf-0.0.5
CATEGORIES=	audio
MASTER_SITES=	#
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://users.suse.com/~mana/ladspa.html
COMMENT=	Some LADSPA plugins for audio EQ biquad filters
LICENSE=	gnu-lgpl-v3

INSTALLATION_DIRS+=	lib/ladspa

do-install:
	${INSTALL_LIB} ${WRKSRC}/vcf.so ${DESTDIR}${BUILDLINK_PREFIX.ladspa}/lib/ladspa

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
