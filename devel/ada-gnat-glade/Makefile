# $NetBSD: Makefile,v 1.1 2025/07/11 06:17:37 dkazankov Exp $

#PKG_DISTNAME=	gnat-glade-code-r135-trunk
#DISTNAME=	${PKG_DISTNAME}
DISTNAME=	${GITHUB_PROJECT}-6.0.1
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-13.0.0
CATEGORIES=	devel
# Original sourceforge site periodically loses the snapshot,
# so we use github clone
MASTER_SITES=	${MASTER_SITE_GITHUB:=dkazankov/}
GITHUB_PROJECT=	gnat-glade
GITHUB_TAG=	v6.0.1
#DISTFILES=	${PKG_DISTNAME}.zip
#SITES.${PKG_DISTNAME}.zip=	-https://sourceforge.net/code-snapshots/svn/g/gn/gnat-glade/code/${PKG_DISTNAME}.zip

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/gnat-glade/
COMMENT=	GNAT Library for Ada Distributed Environment
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/*
CHECK_RELRO_SKIP+=	${GNAT_PKGBASE}/bin/*

USE_LANGUAGES=	c ada

.include "../../mk/bsd.prefs.mk"

# This component now throws an error when compiled with GNAT 6 or 10
GCC_REQD+=	13

GNU_CONFIGURE_PREFIX=	${GNAT_PREFIX}

SUBST_CLASSES+=			replace-shell
SUBST_MESSAGE.replace-shell=	Replace shell in ${SUBST_FILES.replace-shell}
SUBST_STAGE.replace-shell=	pre-configure
SUBST_FILES.replace-shell=	Dist/gnatdist-config.in
SUBST_VARS.replace-shell=	SHELL

# Use C preprocessed symbols on NetBSD
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		select
SUBST_MESSAGE.select=	Replace select with __netbsd_select in ${SUBST_FILES.select}
SUBST_STAGE.select=	pre-configure
SUBST_FILES.select=	Garlic/isthrbio.adb
SUBST_SED.select=	-e "s,\"select\",\"__netbsd_select\","
.endif

post-patch:
	chmod +x ${WRKSRC}/Dist/config.sdefault

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.pkg.mk"
