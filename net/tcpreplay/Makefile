# $NetBSD: Makefile,v 1.16 2007/02/18 18:51:55 adrianp Exp $

DISTNAME=	tcpreplay-2.3.5
PKGREVSION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--without-pcapnav-config

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_SED.conf=		-e "s|libnet-config|libnet11-config|g"
SUBST_SED.conf+=	-e "s|@@LN_INC@@|${BUILDLINK_PREFIX.libnet11}/include/libnet11|g"
SUBST_SED.conf+=	-e "s|@@LN_LIB@@|${BUILDLINK_PREFIX.libnet11}/lib/libnet11|g"
SUBST_MESSAGE.conf=     Fixing configuration script.

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
