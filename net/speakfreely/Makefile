# $NetBSD: Makefile,v 1.15 2004/04/24 23:53:51 wiz Exp $
#

DISTNAME=		speak_freely-7.2
PKGNAME=		speakfreely-7.2
PKGREVISION=		2
CATEGORIES=		net audio
MASTER_SITES=		http://www.fourmilab.ch/speakfree/unix/

MAINTAINER=		johnam@mail.kemper.org
HOMEPAGE=		http://www.fourmilab.ch/speakfree/unix/
COMMENT=		Internet "phone" for UNIX

USE_BUILDLINK3=		YES
NO_CONFIGURE=		YES
USE_PERL5=		YES

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
.include "../../security/openssl/buildlink3.mk"

.if defined(USE_IDEA) && ${USE_IDEA} == "YES"
LICENSE=		no-commercial-use
.endif
.endif

SOUNDDIR=	${PREFIX}/share/speakfreely
MAKE_ENV+=	PERL="${PERL5}" CCFLAGS="${CCFLAGS}" \
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

.include "../../audio/gsm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
