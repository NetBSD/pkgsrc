# $NetBSD: Makefile,v 1.3 2006/02/01 00:10:53 riz Exp $
#

DISTNAME=		zaptel-netbsd-20060127
CATEGORIES=		comms
MASTER_SITES=		http://www.tastylime.net/netbsd/zaptel/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	http://www.tastylime.net/netbsd/zaptel/
COMMENT=	The "zaptel" drivers and utils for the Asterisk Software PBX

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*
INSTALLATION_DIRS=	lkm

ZAPTEL_KERNEL_ENV?=	# empty
BUILD_DEFS+=		ZAPTEL_KERNEL_ENV
MAKE_ENV+=		ZAPTEL_KERNEL_ENV=${ZAPTEL_KERNEL_ENV:Q}
CONF_FILES=		${PREFIX}/share/examples/zaptel/zaptel.conf \
			${PKG_SYSCONFDIR}/zaptel.conf

RCD_SCRIPTS=		ztcfg

.include "../../devel/newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
