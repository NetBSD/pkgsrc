# $NetBSD: Makefile,v 1.15 2005/05/10 12:39:28 manu Exp $
#

DISTNAME=		ipsec-tools-0.6b2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ipsec-tools/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://ipsec-tools.sourceforge.net/
COMMENT=		Ipsec-tools racoon IKE daemon

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=        PKG_OPTIONS.ipsec-tools
PKG_DEFAULT_OPTIONS+=	radius
PKG_SUPPORTED_OPTIONS+=	radius

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mradius)
.  include "../../net/libradius/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libradius
LIBS+=			${BUILDLINK_LDADD.libradius}
.endif

CONFIGURE_ARGS+=	--enable-frag --enable-hybrid
CONFIGURE_ARGS+=	--enable-adminport --enable-dpd
CONFIGURE_ARGS+=	--enable-natt=kernel

PKG_SYSCONFSUBDIR=	racoon
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

SAMPLE_DIR=	${WRKSRC}/src/racoon/samples
EXAMPLE_DIR=	${PREFIX}/share/examples/ipsec-tools

pre-configure:
	${RM} -f ${WRKSRC}/src/racoon/cfparse.c
	${RM} -f ${WRKSRC}/src/racoon/cftoken.c

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}/roadwarrior
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}/roadwarrior/client
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}/roadwarrior/server
	${INSTALL_DATA} ${SAMPLE_DIR}/psk.txt ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/psk.txt.in ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/psk.txt.sample ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.in ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-gssapi ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-inherit ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-natt ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-plainrsa ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/roadwarrior/README \
	    ${EXAMPLE_DIR}/roadwarrior
	${INSTALL_DATA} ${SAMPLE_DIR}/roadwarrior/client/racoon.conf \
	    ${EXAMPLE_DIR}/roadwarrior/client
	${INSTALL_DATA} ${SAMPLE_DIR}/roadwarrior/client/phase1-up.sh \
	    ${EXAMPLE_DIR}/roadwarrior/client
	${INSTALL_DATA} ${SAMPLE_DIR}/roadwarrior/client/phase1-down.sh \
	    ${EXAMPLE_DIR}/roadwarrior/client
	${INSTALL_DATA} ${SAMPLE_DIR}/roadwarrior/server/racoon.conf \
	    ${EXAMPLE_DIR}/roadwarrior/server
	${INSTALL_DATA} ${SAMPLE_DIR}/roadwarrior/server/racoon.conf-radius \
	    ${EXAMPLE_DIR}/roadwarrior/server

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
