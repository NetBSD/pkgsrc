# $NetBSD: Makefile,v 1.6 2022/06/30 11:18:48 nia Exp $

VERSION=	22.2.4
DISTNAME=	autojump-${VERSION}
PKGREVISION=	4
CATEGORIES=	shells
MASTER_SITES=	-https://github.com/joelthelion/autojump/archive/release-v${VERSION}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joelthelion/autojump/
COMMENT=	Change directory command that learns to easily navigate directories
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/autojump-release-v${VERSION}

INSTALLATION_DIRS+=	bin share/autojump ${PKGMANDIR}/man1

REPLACE_PYTHON+=	bin/autojump bin/*.py

do-build:
	# nothing

# the install.py script is not friendly to destdir installation as non-root
# cd ${WRKSRC} && ${ENV} SHELL=${BASH} ${PYTHONBIN} install.py -fs -p ${PREFIX} -d ${DESTDIR}
# see also https://github.com/joelthelion/autojump/issues/338
do-install:
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} autojump autojump_argparse.py autojump_data.py autojump_utils.py ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} icon.png ${DESTDIR}${PREFIX}/share/autojump
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} autojump*sh ${DESTDIR}${PREFIX}/share/autojump
	cd ${WRKSRC}/docs && ${INSTALL_SCRIPT} autojump.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
