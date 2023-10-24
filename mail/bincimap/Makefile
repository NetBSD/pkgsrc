# $NetBSD: Makefile,v 1.2 2023/10/24 22:09:41 wiz Exp $

DISTNAME=		bincimap-1.2.13final
PKGNAME=		${DISTNAME:S/final$//}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bincimap/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/bincimap/
COMMENT=		IMAP server for Maildir using checkpassword
LICENSE=		gnu-gpl-v2

DEPENDS+=		daemontools-[0-9]*:../../sysutils/daemontools
DEPENDS+=		pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives
DEPENDS+=		qmail-acceptutils-[0-9]*:../../mail/qmail-acceptutils

USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/${EGDIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
INSTALL_MAKE_FLAGS=	sysconfdir=${PREFIX:Q}/${EGDIR:Q}

REPLACE_PERL=		conf/checkpassword.pl conf/toimapdir conf/tomaildir++

SUBST_CLASSES+=		nobody
SUBST_STAGE.nobody=	pre-configure
SUBST_FILES.nobody=	conf/bincimap.conf.in
SUBST_VARS.nobody=	BINCIMAP_USER BINCIMAP_GROUP

PKG_USERS_VARS+=	BINCIMAP_USER
PKG_GROUPS_VARS+=	BINCIMAP_GROUP
PKG_GROUPS+=		${BINCIMAP_GROUP}
PKG_USERS+=		${BINCIMAP_USER}:${BINCIMAP_GROUP}

EGDIR=			share/examples/${PKGBASE}
CONF_FILES+=		${PREFIX}/${EGDIR}/${PKGBASE}.conf \
			${PKG_SYSCONFDIR}/${PKGBASE}.conf
RCD_SCRIPTS=		bincimapd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${EGDIR}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
