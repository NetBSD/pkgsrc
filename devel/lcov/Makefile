# $NetBSD: Makefile,v 1.12 2019/08/11 13:18:45 wiz Exp $
#

DISTNAME=	lcov-1.13
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ltp/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://ltp.sourceforge.net/coverage/lcov.php
COMMENT=	Front-end for GCC's coverage testing tool gcov

NO_BUILD=		yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/examples/lcov
USE_TOOLS+=		perl

REPLACE_PERL=		bin/gendesc bin/genhtml bin/geninfo bin/genpng bin/lcov

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=      pre-configure
SUBST_FILES.egdir=	bin/genhtml
SUBST_FILES.egdir+=	bin/geninfo
SUBST_FILES.egdir+=	bin/lcov
SUBST_SED.egdir=	-e 's,"/etc/lcovrc","'${PKG_SYSCONFDIR}/lcovrc'",g'

CONF_FILES=	${PREFIX}/share/examples/lcov/lcovrc \
		${PKG_SYSCONFDIR}/lcovrc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lcov ${DESTDIR}${PREFIX}/bin/lcov
	${INSTALL_SCRIPT} ${WRKSRC}/bin/genhtml ${DESTDIR}${PREFIX}/bin/genhtml
	${INSTALL_SCRIPT} ${WRKSRC}/bin/geninfo ${DESTDIR}${PREFIX}/bin/geninfo
	${INSTALL_SCRIPT} ${WRKSRC}/bin/genpng ${DESTDIR}${PREFIX}/bin/genpng
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gendesc ${DESTDIR}${PREFIX}/bin/gendesc
	${INSTALL_MAN} ${WRKSRC}/man/lcov.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lcov.1
	${INSTALL_MAN} ${WRKSRC}/man/genhtml.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/genhtml.1
	${INSTALL_MAN} ${WRKSRC}/man/geninfo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/geninfo.1
	${INSTALL_MAN} ${WRKSRC}/man/genpng.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/genpng.1
	${INSTALL_MAN} ${WRKSRC}/man/gendesc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gendesc.1
	${INSTALL_MAN} ${WRKSRC}/man/lcovrc.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/lcovrc.5
	${INSTALL_DATA} ${WRKSRC}/lcovrc ${DESTDIR}${PREFIX}/share/examples/lcov/lcovrc

.include "../../mk/bsd.pkg.mk"
