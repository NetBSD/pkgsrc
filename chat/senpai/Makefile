# $NetBSD: Makefile,v 1.27 2024/06/13 13:46:55 bsiegert Exp $

DISTNAME=	senpai-v0.3.0
PKGNAME=	${DISTNAME:S,-v,-,}
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	-https://git.sr.ht/~delthas/senpai/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~delthas/senpai/
COMMENT=	Modern terminal IRC client
LICENSE=	isc

TOOL_DEPENDS+=		scdoc-[0-9]*:../../textproc/scdoc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
GO_BUILD_PATTERN=	./...

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/senpai \
		${DESTDIR}${PREFIX}/bin

# Generate manpages and install them
post-install:
	scdoc < ${WRKSRC}/doc/senpai.1.scd > ${WRKSRC}/doc/senpai.1
	scdoc < ${WRKSRC}/doc/senpai.5.scd > ${WRKSRC}/doc/senpai.5
	${INSTALL_MAN} ${WRKSRC}/doc/senpai.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/senpai.1
	${INSTALL_MAN} ${WRKSRC}/doc/senpai.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/senpai.5

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
