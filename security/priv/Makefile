# $NetBSD: Makefile,v 1.24 2021/04/11 07:10:06 kim Exp $
#

DISTNAME=	priv-1.0-beta2
PKGNAME=	priv-1.0beta2
PKGREVISION=	5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.thistledown.com.au/pub/simonb/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Execute commands as a different user
LICENSE=	original-bsd

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

# XXX: Regenerate patches/patch-configure and patches/patch-config.h.in
#      if patches/patch-configure.in changes.
#
# Having these additional patch files instead of running autoreconf
# makes priv available sooner when doing a fresh pkgsrc build, as there
# will be no need to pull in other (possibly large) tools.
#
#USE_TOOLS=	autoconf automake autoreconf
#
#pre-configure:
#	cd "${WRKSRC}" && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
