# $NetBSD: Makefile,v 1.2 1999/10/26 16:48:48 jlam Exp $
#

PKGNAME=		speakfreely-crypto-7.1
CONFLICTS=		speakfreely-*

.if exists (/usr/include/openssl/blowfish.h)
HAVE_LIBCRYPTO=		yes
OPENSSLDIR=		/usr
.else
HAVE_LIBCRYPTO=		no
#HAVE_LIBCRYPTO=	yes
#OPENSSLDIR=		${LOCALBASE}
#DEPENDS+=		openssl-*:../../security/openssl
.endif

LICENSE=                no-commercial-use	# uses IDEA algorithm
RESTRICTED=             "Crypto; export-controlled"

MAKE_ENV+=		CRYPTO=yes \
			HAVE_LIBCRYPTO="${HAVE_LIBCRYPTO}" \
			OPENSSLDIR="${OPENSSLDIR}" \

FILESDIR=		${.CURDIR}/../../net/speakfreely/files
PATCHDIR=		${.CURDIR}/../../net/speakfreely/patches
PKGDIR=			${.CURDIR}/../../net/speakfreely/pkg

.include "../../net/speakfreely/Makefile.common"
