# $NetBSD: Makefile,v 1.17 2020/04/28 04:29:01 rillig Exp $

DISTNAME=	dhcpd-pools-2.27
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dhcpd-pools/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://dhcpd-pools.sourceforge.net/
COMMENT=	ISC dhcpd lease analysis and reporting
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-dhcpd-leases=${VARBASE}/db/dhcpd.leases

BUILD_DEFS+=		VARBASE
REPLACE_PERL=		contrib/snmptest.pl
USE_TOOLS+=		perl:run

LDFLAGS.SunOS+=	-lnsl

.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
