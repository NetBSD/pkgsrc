# $NetBSD: Makefile,v 1.4 2000/04/27 03:29:42 jlam Exp $
#

DISTNAME=		speak_freely-7.1
PKGNAME=		speakfreely-7.1
CATEGORIES=		net audio
MASTER_SITES=		http://www.fourmilab.ch/speakfree/unix/

MAINTAINER=		johnam@mail.kemper.org
HOMEPAGE=		http://www.fourmilab.ch/speakfree/unix/

DEPENDS+=		gsm-1.0.10:../../audio/gsm

USE_PERL=		yes
PERL_PATH=		${LOCALBASE}/bin/perl

MIRROR_DISTFILE=	no			# source includes crypto code

NO_CONFIGURE=		yes

BUILD_DEFS+=		SPEAKFREELY_OPTIONS USE_CRYPTO USE_IDEA

.include "../../mk/bsd.prefs.mk"

USE_CRYPTO?=		YES
USE_IDEA?=		NO

# SPEAKFREELY_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	halfduplex	for if sound card doesn't support full-duplex sound
#
SPEAKFREELY_OPTIONS?=   halfduplex

.if ${SPEAKFREELY_OPTIONS:Mhalfduplex} == "halfduplex"
CCFLAGS+=		-DHALF_DUPLEX
.endif

.if defined(USE_CRYPTO) && ${USE_CRYPTO} == "YES"
HAVE_LIBCRYPTO=		YES
USE_SSL=		# defined
RESTRICTED=		"Crypto; export-controlled"

.if defined(USE_IDEA) && ${USE_IDEA} == "YES"
LICENSE=		no-commercial-use
.endif
.endif

SOUNDDIR=	${PREFIX}/share/speakfreely
MAKE_ENV+=	PERL="${PERL_PATH}" CCFLAGS="${CCFLAGS}" \
		SOUNDDIR="${SOUNDDIR}"
MAKE_ENV+=	USE_CRYPTO="${USE_CRYPTO}" HAVE_LIBCRYPTO="${HAVE_LIBCRYPTO}" \
		SSLBASE="${SSLBASE}" USE_IDEA="${USE_IDEA}"
MAKE_ENV+=	HAVE_GSM=YES HAVE_MD5=YES
MAKE_ENV+=	DOMAIN=

post-extract:
	${MV} ${WRKSRC}/sfspeaker.1 ${WRKSRC}/sfspeaker.1.in

pre-build:
	${SED} -e "s,@SOUNDDIR@,${SOUNDDIR},g" \
		< ${WRKSRC}/sfspeaker.1.in > ${WRKSRC}/sfspeaker.1

post-install:
	${INSTALL_DATA_DIR} ${SOUNDDIR}
	${INSTALL_DATA} ${WRKSRC}/busy.au ${SOUNDDIR}
	${INSTALL_DATA} ${WRKSRC}/ring.au ${SOUNDDIR}

.include "../../mk/bsd.pkg.mk"
