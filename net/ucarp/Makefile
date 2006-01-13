# $NetBSD: Makefile,v 1.6 2006/01/13 18:42:48 wiz Exp $
#

DISTNAME=		ucarp-1.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ucarp.org/pub/ucarp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joel@carnat.net
HOMEPAGE=		http://www.ucarp.org/
COMMENT=		Common Address Redundancy Protocol (CARP) for Unix

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

# pcap_freecode with one argument only
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.6.0

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ucarp
	for DOC in AUTHORS COPYING NEWS README; do \
		${INSTALL_DATA} ${WRKSRC}/$$DOC ${PREFIX}/share/doc/ucarp; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ucarp
	${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/*sh \
		${PREFIX}/share/examples/ucarp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
