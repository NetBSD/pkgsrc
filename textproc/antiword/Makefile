# $NetBSD: Makefile,v 1.27 2017/07/12 12:54:28 wiz Exp $

DISTNAME=	antiword-0.37
PKGREVISION=	2
CATEGORIES=	textproc converters print
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.winfield.demon.nl/index.html
COMMENT=	Free MS Word to text and PostScript converter
LICENSE=	gnu-gpl-v2

CONFLICTS=	siag<3.6.1

USE_TOOLS+=	mktemp:run

CFLAGS.SunOS+=	-D__STDC_ISO_10646__
MAKEFLAGS+=	LDFLAGS=${LDFLAGS:Q}

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	kantiword

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	cd ${WRKSRC} ; \
	for pf in antiword.h Docs/antiword.1 ; do \
	  ${MV} $${pf} $${pf}.old ; \
	  ${SED} -e "s|/usr/share|${PREFIX}/share|g" $${pf}.old > $${pf} ; \
	done

.include "../../mk/bsd.pkg.mk"
