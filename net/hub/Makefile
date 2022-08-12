# $NetBSD: Makefile,v 1.68 2022/08/12 20:38:00 bsiegert Exp $

DISTNAME=	hub-2.14.2
PKGREVISION=	28
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=github/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://hub.github.com/
COMMENT=	Command-line tool that makes git easier to use with GitHub
LICENSE=	mit

GO_BUILD_PATTERN=	./...

.include "go-modules.mk"

DEPENDS+=		git-base>=1.7.3:../../devel/git-base

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix hub name in hub(1) man page
SUBST_FILES.man=	share/man/man1/hub.1.md
SUBST_SED.man+=		-e 's/\$$ git/$$ hub/'
SUBST_SED.man+=		-e '/\$$ GITHUB_HOST=/ s/ git clone / hub clone /'

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

CHECK_RELRO_SKIP+=	bin/hub

# List of hub commands to generate man pages, HELP_CMD list of ${WRKSRC}/Makefile
HUB_COMMANDS=	alias \
		api \
		browse \
		ci-status \
		compare \
		create \
		delete \
		fork \
		gist \
		pr \
		pull-request \
		release \
		issue \
		sync

# Generate hub man pages
pre-install:
.for hc in ${HUB_COMMANDS}
	cd ${WRKSRC} && \
	    ../.gopath/bin/hub help ${hc} --plain-text > \
	        share/man/man1/hub-${hc}.1.md
.endfor
	cd ${WRKSRC} && \
	    ../.gopath/bin/md2roff-bin --manual="hub manual" \
		--version=${PKGVERSION_NOREV} \
		--template=man-template.html \
		share/man/man1/*.md

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/hub ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/hub.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for hc in ${HUB_COMMANDS}
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/hub-${hc}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
