# $NetBSD: Makefile,v 1.30 2022/08/19 02:00:50 tnn Exp $
#

DISTNAME=	colorize-0.3.4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=raszi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/raszi/colorize
COMMENT=	Log colorize perl script
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

USE_TOOLS+=		gunzip perl:run

SUBST_CLASSES+=		color
SUBST_STAGE.color=	pre-configure
SUBST_MESSAGE.color=	Fixing hard-coded paths.
SUBST_FILES.color=	colorize colorize.1
SUBST_SED.color+=	-e "s,/etc/colorizerc,${PKG_SYSCONFDIR}/colorizerc,"

REPLACE_PERL+=		colorize
REPLACE_SH+=		examples/*.sh

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/examples/colorize
INSTALLATION_DIRS+=	share/doc/colorize

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/colorize.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/colorize ${DESTDIR}${PREFIX}/bin/colorize
	${INSTALL_DATA} ${WRKSRC}/colorizerc				\
		${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_MAN} ${WRKSRC}/colorize.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/colorize.1
	cd ${WRKSRC} && ${INSTALL_DATA} README TIPS			\
		${DESTDIR}${PREFIX}/share/doc/colorize
	${INSTALL_SCRIPT} ${WRKSRC}/examples/colorize-fifo.sh		\
		${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_SCRIPT} ${WRKSRC}/examples/colorize-tail.sh		\
		${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_DATA} ${WRKSRC}/examples/Xlog.tar			\
		${DESTDIR}${PREFIX}/share/examples/colorize

.include "../../mk/bsd.pkg.mk"
