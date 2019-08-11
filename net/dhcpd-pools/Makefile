# $NetBSD: Makefile,v 1.14 2019/08/11 13:22:07 wiz Exp $

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

SUBST_CLASSES+=		fix-name
SUBST_STAGE.fix-name=	pre-configure
SUBST_MESSAGE.fix-name=	Removing program_invocation_short_name.
SUBST_FILES.fix-name=	src/dhcpd-pools.c src/other.c src/sort.c
SUBST_SED.fix-name=	-e 's,program_invocation_short_name,"dhcpd-pools",g'

LDFLAGS.SunOS+=	-lnsl

.include "../../devel/uthash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
