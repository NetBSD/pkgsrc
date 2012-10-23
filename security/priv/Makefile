# $NetBSD: Makefile,v 1.19 2012/10/23 18:16:52 asau Exp $
#

DISTNAME=	priv-1.0-beta2
PKGNAME=	priv-1.0beta2
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.thistledown.com.au/pub/simonb/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Execute commands as a different user

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
SUBST_CLASSES+=		sysconfdir
SUBST_STAGE.sysconfdir=	post-configure
SUBST_FILES.sysconfdir=	priv.1
SUBST_SED.sysconfdir=	-e "s|/usr/local/etc/|${PKG_SYSCONFDIR}/|g"

INSTALL_MAKE_FLAGS=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

SPECIAL_PERMS+=	bin/priv ${SETUID_ROOT_PERMS}

OWN_DIRS=	${PKG_SYSCONFDIR}/priv

.include "../../mk/bsd.pkg.mk"
