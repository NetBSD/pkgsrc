# $NetBSD: Makefile,v 1.9 2024/03/24 10:48:09 js Exp $

PKGNAME=	ppc-morphos-${DISTNAME}
DISTNAME=	sdk-20230510
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/
EXTRACT_SUFX=	.lha

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	SDK for ppc-morphos-gcc
LICENSE=	morphos-sdk-license

RESTRICTED=		No redistribution without permission from MorphOS Team
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

WRKSRC=		${WRKDIR}/morphossdk
USE_TOOLS+=	xzcat gtar gsed
USE_LANGUAGES=	# none

do-build:

do-install:
	${RUN} ${MKDIR} ${DESTDIR}${PREFIX}/gg
	# As per https://bigfoot.morphos-team.net/files/setup-cross-sdk.sh
	${RUN} cd ${WRKSRC} && ${XZCAT} sdk.pack | \
		${GTAR} -C ${DESTDIR}${PREFIX}/gg \
			--wildcards \
			--transform "s,^Development/[Gg][Gg]/,," \
			--exclude "ldscripts" \
			-x \
			"Development/[Gg][Gg]/ppc-morphos" \
			"Development/[Gg][Gg]/include" \
			"Development/[Gg][Gg]/includestd" \
			"Development/[Gg][Gg]/os-include" \
			"Development/[Gg][Gg]/bin/*.pl"
	gsed -i 's,/usr/bin/perl,${PERL5},g' \
		${DESTDIR}${PREFIX}/gg/bin/cvinclude.pl \
		${DESTDIR}${PREFIX}/gg/bin/genfd.pl
	# No files should be executable other than those in ${PREFIX}/gg/bin.
	find ${DESTDIR}${PREFIX}/gg -type f -exec chmod 644 {} ';'
	find ${DESTDIR}${PREFIX}/gg/bin -type f -exec chmod 755 {} ';'

.include "../../mk/bsd.pkg.mk"
