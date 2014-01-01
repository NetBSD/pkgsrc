# $NetBSD: Makefile,v 1.40 2014/01/01 11:52:33 wiz Exp $
#
# The following packages use the same distfile, even if they
# currently do not use a common Makefile fragment. Please look at
# them when updating this package
# pkgsrc/security/pinentry-gtk
# pkgsrc/security/pinentry-gtk2
# pkgsrc/security/pinentry-qt
# pkgsrc/security/pinentry-qt4

DISTNAME=		pinentry-0.8.3
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}

INFO_FILES=		yes

.include "options.mk"

.if defined(PINENTRY_DEFAULT)
post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf pinentry-${PINENTRY_DEFAULT} pinentry
.endif

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0


.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
