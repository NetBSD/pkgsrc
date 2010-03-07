# $NetBSD: Makefile,v 1.8 2010/03/07 23:56:17 jnemeth Exp $
#

DISTNAME=		zaptel-netbsd-20060127
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://www.tastylime.net/netbsd/zaptel/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tastylime.net/netbsd/zaptel/
COMMENT=	The "zaptel" drivers and utils for the Asterisk Software PBX

ONLY_FOR_PLATFORM=	NetBSD-[2-4]*-*
INSTALLATION_DIRS=	lkm

ZAPTEL_KERNEL_ENV?=	# empty
BUILD_DEFS+=		ZAPTEL_KERNEL_ENV
MAKE_ENV+=		ZAPTEL_KERNEL_ENV=${ZAPTEL_KERNEL_ENV:Q}
MAKE_ENV+=		BSDSRCDIR=${BSDSRCDIR}
CONF_FILES=		${PREFIX}/share/examples/zaptel/zaptel.conf \
			${PKG_SYSCONFDIR}/zaptel.conf

RCD_SCRIPTS=		ztcfg

.include "../../mk/bsd.prefs.mk"

.if !exists(${BSDSRCDIR}/sys)
PKG_FAIL_REASON+=	"${PKGNAME} needs kernel sources in ${BSDSRCDIR}."
.endif

.include "../../devel/newt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
