# $NetBSD: Makefile,v 1.1.1.1 2004/11/09 22:42:20 manu Exp $
#

DISTNAME=		ipsec-tools-0.5.pre20041109
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ipsec-tools/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://ovh.dl.sourceforge.net/sourceforge/ipsec-tools/
COMMENT=		Ipsec-tools racoon IKE daemon

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-libradius --enable-natt
CONFIGURE_ARGS+=	--enable-frag --enable-hybrid

BUILDLINK_DEPMETHOD.libradius-linux?=	build

BUILD_DEPEND+=		libradius-linux>=20040827nb1:../../net/libradius

SAMPLE_DIR=	${WRKSRC}/src/racoon/samples
EXAMPLE_DIR=	${PREFIX}/share/examples/ipsec-tools
post-install:
	${INSTALL_DATA_DIR} ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/psk.txt ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/psk.txt.in ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/psk.txt.sample ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.in ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-cvpn ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-gssapi ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-inherit ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-natt ${EXAMPLE_DIR}
	${INSTALL_DATA} ${SAMPLE_DIR}/racoon.conf.sample-plainrsa ${EXAMPLE_DIR}

.include "../../net/libradius/buildlink3.mk" ${EXAMPLE_DIR}
.include "../../mk/bsd.pkg.mk" ${EXAMPLE_DIR}
