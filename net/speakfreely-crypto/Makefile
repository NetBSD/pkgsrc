# $NetBSD: Makefile,v 1.1.1.1 1999/10/11 05:49:03 jlam Exp $
#

DISTNAME=		speak_freely-7.1
PKGNAME=		speakfreely-crypto-7.1
CATEGORIES=		net audio
MASTER_SITES=		http://www.fourmilab.ch/speakfree/unix/

MAINTAINER=		johnam@mail.kemper.org
HOMEPAGE=		http://www.fourmilab.ch/speakfree/unix/

CONFLICTS=		speakfreely-*

DEPENDS+=		gsm-1.0.10:../../audio/gsm

.if exists (/usr/include/openssl/blowfish.h)
HAVE_LIBCRYPTO=		yes
OPENSSLDIR=		/usr
.else
HAVE_LIBCRYPTO=		no
#HAVE_LIBCRYPTO=	yes
#OPENSSLDIR=		${LOCALBASE}
#DEPENDS+=		openssl-*:../../security/openssl
.endif

USE_PERL=		yes
PERL_PATH=		${LOCALBASE}/bin/perl

LICENSE=                no-commercial-use	# uses IDEA algorithm
MIRROR_DISTFILE=	no			# source includes crypto code
RESTRICTED=             "Crypto; export-controlled"

NO_CONFIGURE=		yes

BUILD_DEFS+=		SPEAKFREELY_OPTIONS

.include "../../mk/bsd.prefs.mk"

# SPEAKFREELY_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	halfduplex	for if sound card doesn't support full-duplex sound
#
SPEAKFREELY_OPTIONS?=   halfduplex

.if ${SPEAKFREELY_OPTIONS:Mhalfduplex} == "halfduplex"
CCFLAGS+=		-DHALF_DUPLEX
.endif

SOUNDDIR=		${PREFIX}/share/speakfreely
MAKE_ENV+=		PERL="${PERL_PATH}" CCFLAGS="${CCFLAGS}" \
			SOUNDDIR="${SOUNDDIR}" HAVE_GSM=yes
MAKE_ENV+=		CRYPTO=yes \
			HAVE_LIBCRYPTO="${HAVE_LIBCRYPTO}" \
			OPENSSLDIR="${OPENSSLDIR}" \
MAKE_ENV+=		HAVE_MD5=yes

post-extract:
	${MV} ${WRKSRC}/sfspeaker.1 ${WRKSRC}/sfspeaker.1.in

pre-build:
	${SED} -e "s,@SOUNDDIR@,${SOUNDDIR},g" ${WRKSRC}/sfspeaker.1.in \
		> ${WRKSRC}/sfspeaker.1

post-install:
	${INSTALL_DATA_DIR} ${SOUNDDIR}
	${INSTALL_DATA} ${WRKSRC}/busy.au ${SOUNDDIR}
	${INSTALL_DATA} ${WRKSRC}/ring.au ${SOUNDDIR}

.include "../../mk/bsd.pkg.mk"
