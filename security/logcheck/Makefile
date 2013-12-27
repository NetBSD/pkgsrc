# $NetBSD: Makefile,v 1.20 2013/12/27 03:06:44 dholland Exp $

DISTNAME=	logcheck-1.1.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sentrytools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sentrytools/
COMMENT=	Auditing tool for system logs on Unix boxes
LICENSE=	gnu-gpl-v2

PKG_SYSCONFSUBDIR=	logcheck
EGDIR=			${PREFIX}/share/examples/logcheck
TEMPDIR=		${VARBASE}/adm/tmp

.for f in hacking ignore violations violations.ignore
CONF_FILES_PERMS+=	${EGDIR}/logcheck.${f} ${PKG_SYSCONFDIR}/logcheck.${f}\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
.endfor

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing hard-coded paths.
SUBST_FILES.prefix=	Makefile systems/freebsd/logcheck.sh
SUBST_SED.prefix=	-e "s+/usr/local+${PREFIX}+g"
SUBST_SED.prefix+=	-e "s+@PKG_SYSCONFDIR@+${PKG_SYSCONFDIR}+g"
SUBST_SED.prefix+=	-e "s+@TEMPDIR@+${TEMPDIR}+g"

INSTALLATION_DIRS+=	bin ${EGDIR}

OWN_DIRS_PERMS+=	${TEMPDIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

SPECIAL_PERMS+=		${PREFIX}/bin/logcheck.sh ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
SPECIAL_PERMS+=		${PREFIX}/bin/logtail ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/logtail ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/systems/freebsd/logcheck.sh \
		${DESTDIR}${PREFIX}/bin
.for f in hacking ignore violations violations.ignore
	${INSTALL_DATA} ${WRKSRC}/systems/freebsd/logcheck.${f} \
		${DESTDIR}${EGDIR}
.endfor

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
