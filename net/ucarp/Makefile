# $NetBSD: Makefile,v 1.16 2013/12/10 17:56:23 jperkin Exp $
#

DISTNAME=		ucarp-1.5.2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ucarp.org/pub/ucarp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joel@carnat.net
HOMEPAGE=		http://www.ucarp.org/project/ucarp
COMMENT=		Common Address Redundancy Protocol (CARP) for Unix

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		msgfmt

# pcap_freecode with one argument only
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6.0

INSTALLATION_DIRS+=	share/doc/ucarp share/examples/ucarp

post-install:
	for DOC in AUTHORS COPYING NEWS README; do \
		${INSTALL_DATA} ${WRKSRC}/$$DOC ${DESTDIR}${PREFIX}/share/doc/ucarp; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/*sh \
	    ${DESTDIR}${PREFIX}/share/examples/ucarp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
