# $NetBSD: Makefile,v 1.29 2022/06/28 11:34:47 wiz Exp $
#

DISTNAME=	colorize_0.3.0
PKGNAME=	colorize-0.3.0
PKGREVISION=	11
CATEGORIES=	misc
MASTER_SITES=	http://colorize.raszi.hu/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://colorize.raszi.hu/
COMMENT=	Log colorize perl script

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
NO_BUILD=	yes

USE_TOOLS+=		gunzip perl:run
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		color
SUBST_STAGE.color=	pre-configure
SUBST_MESSAGE.color=	Fixing hard-coded paths.
SUBST_FILES.color=	colorize.pl examples/*.sh
SUBST_SED.color+=	-e "s,/usr/bin/perl,${LOCALBASE}/bin/perl,"
SUBST_SED.color+=	-e "s,/etc/colorizerc,${PKG_SYSCONFDIR}/colorizerc,"
SUBST_SED.color+=	-e "s,/bin/bash,"${SH:Q}","

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/colorize.pl.1.gz
	${GUNZIP_CMD} ${WRKSRC}/examples/colorize-fifo.sh.gz
	${GUNZIP_CMD} ${WRKSRC}/examples/colorize-tail.sh.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/colorize.pl ${DESTDIR}${PREFIX}/bin/colorize
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_DATA} ${WRKSRC}/colorizerc				\
		${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_MAN} ${WRKSRC}/colorize.pl.1				\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/colorize.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/colorize
	cd ${WRKSRC} && ${INSTALL_DATA} README TIPS			\
		${DESTDIR}${PREFIX}/share/doc/colorize
	${INSTALL_SCRIPT} ${WRKSRC}/examples/colorize-fifo.sh		\
		${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_SCRIPT} ${WRKSRC}/examples/colorize-tail.sh		\
		${DESTDIR}${PREFIX}/share/examples/colorize
	${INSTALL_DATA} ${WRKSRC}/examples/Xlog.tar.gz			\
		${DESTDIR}${PREFIX}/share/examples/colorize

.include "../../mk/bsd.pkg.mk"
