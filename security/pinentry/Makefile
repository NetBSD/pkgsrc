# $NetBSD: Makefile,v 1.33 2012/08/15 17:47:56 drochner Exp $
#

DISTNAME=		pinentry-0.8.2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

PKG_DESTDIR_SUPPORT=	user-destdir

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
