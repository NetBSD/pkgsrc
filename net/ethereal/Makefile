# $NetBSD: Makefile,v 1.70.2.3 2003/06/19 00:07:48 grant Exp $

DISTNAME=		ethereal-0.9.12
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
 			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/ \
 			ftp://ftp.planetmirror.com/pub/ethereal/ \
 			ftp://gd.tuwien.ac.at/infosys/security/ethereal/ \
 			http://www.ethereal.com/distribution/ \
 			http://ftp.sunet.se/pub/network/monitoring/ethereal/ \
 			http://ethereal.netarc.jp/distribution/ \
 			ftp://ftp.ethereal.com/pub/ethereal/old-versions/
EXTRACT_SUFX=		.tar.bz2
  
MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.ethereal.com/
COMMENT=		Network protocol analyzer

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_PERL5=		build

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-static=no
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_PREFIX.gtk}
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-net-snmp=${BUILDLINK_PREFIX.net-snmp}
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

.include "../../mk/bsd.prefs.mk"

# It really wants gnu sed or xpg4/bin/sed on solaris.
.if ${OPSYS} == SunOS
.include "../../textproc/gsed/buildlink2.mk"
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
