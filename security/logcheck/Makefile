# $NetBSD: Makefile,v 1.16 2006/06/16 09:20:32 rillig Exp $

DISTNAME=	logcheck-1.1.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sentrytools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sentrytools/
COMMENT=	Auditing tool for system logs on Unix boxes


OWN_DIRS=	/var/adm/tmp /var/adm

PKG_SYSCONFSUBDIR=	logcheck
EGDIR=		${PREFIX}/share/examples/logcheck
CONF_FILES=
.for f in hacking ignore violations violations.ignore
CONF_FILES+=	${EGDIR}/logcheck.${f} ${PKG_SYSCONFDIR}/logcheck.${f}
.endfor

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing hard-coded paths.
SUBST_FILES.prefix=	Makefile systems/freebsd/logcheck.sh
SUBST_SED.prefix=	-e "s+/usr/local+${PREFIX}+g"
SUBST_SED.prefix+=	-e "s+@PKG_SYSCONFDIR@+${PKG_SYSCONFDIR}+g"

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
