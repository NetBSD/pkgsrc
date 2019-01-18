# $NetBSD: Makefile,v 1.16 2019/01/18 22:08:16 bsiegert Exp $

DISTNAME=	makeself-2.4.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=megastep/}
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.run

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.megastep.org/makeself/
COMMENT=	Neat script to make self-extracting archives

REPLACE_SH=	makeself.sh

NO_BUILD=	yes

INSTALLATION_DIRS=	bin

# The DISPLAY thing is to prevent the script from trying to launch a xterm
# just to extract the source.
pre-patch:
	cd ${WRKDIR} && ${SETENV} DISPLAY="" ${SH} ${DISTFILES}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makeself.sh \
		${DESTDIR}${PREFIX}/bin/makeself

.include "../../mk/bsd.pkg.mk"
