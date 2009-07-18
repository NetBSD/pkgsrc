# $NetBSD: Makefile,v 1.43 2009/07/18 13:11:57 wiz Exp $

DISTNAME=	libtasn1-2.2
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GNU:=gnutls/} \
		ftp://ftp.gnutls.org/pub/gnutls/libtasn1/ \
		ftp://ftp.gnupg.org/gcrypt/alpha/gnutls/libtasn1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	ASN.1 structure parser library
LICENSE= 	gnu-fdl-v1.3 AND gnu-lgpl-v2.1 AND gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"
# Mac OS X has no prototype for getopt_long and no declaration for
# struct option, so ignore getopt_long() even though the test succeeds.
.if ${OPSYS} == "Darwin"
CONFIGURE_ENV+=		ac_cv_func_getopt_long=no
CFLAGS+=	-fno-common

# The "gnu" library ends up being empty and Mac OS X's "ar" doesn't like
# to create empty archives. Just don't build the library.
SUBST_CLASSES+=		gllib
SUBST_STAGE.gllib=	post-configure
SUBST_FILES.gllib=	lib/Makefile
SUBST_SED.gllib=	-e "s/SUBDIRS = gllib//"
.endif

.include "../../mk/bsd.pkg.mk"
