# $NetBSD: Makefile,v 1.23 2010/02/07 15:36:58 drochner Exp $
#

DISTNAME=		pinentry-0.7.6
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/

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
	${LN} -sf ${DESTDIR}${PREFIX}/bin/pinentry-${PINENTRY_DEFAULT} \
		${DESTDIR}${PREFIX}/bin/pinentry
.endif

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
