# $NetBSD: Makefile,v 1.59.2.1 2002/06/23 18:55:12 jlam Exp $

DISTNAME=		ethereal-0.9.4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.ethereal.com/
COMMENT=		Network protocol analyzer

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-ucdsnmp=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_DIR}

.include "../../devel/zlib/buildlink.mk"
.include "../../net/libpcap/buildlink.mk"
.include "../../net/ucd-snmp/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"

.include "../../mk/bsd.pkg.mk"
