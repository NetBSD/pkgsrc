# $NetBSD: Makefile,v 1.9 2004/04/25 03:38:34 snj Exp $

DISTNAME=	logcheck-1.1.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sentrytools/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sentrytools/
COMMENT=	Auditing tool for system logs on Unix boxes

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES

OWN_DIRS=	/var/adm/tmp /var/adm

PKG_SYSCONFSUBDIR=	logcheck
EGDIR=		${PREFIX}/share/examples/logcheck
CONF_FILES=
.for f in hacking ignore violations violations.ignore
CONF_FILES+=	${EGDIR}/logcheck.$f ${PKG_SYSCONFDIR}/logcheck.$f
.endfor
.undef f

pre-configure:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	@${SED} -e "s+/usr/local+${PREFIX}+g" \
		< ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/systems/freebsd/logcheck.sh \
		${WRKSRC}/systems/freebsd/logcheck.sh.old
	@${SED} -e "s+/usr/local+${PREFIX}+g" \
		-e "s+@PKG_SYSCONFDIR@+${PKG_SYSCONFDIR}+g" \
		${WRKSRC}/systems/freebsd/logcheck.sh.old > \
		${WRKSRC}/systems/freebsd/logcheck.sh

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
