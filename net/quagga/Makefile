# $NetBSD: Makefile,v 1.70 2022/06/28 11:35:19 wiz Exp $
#
DISTNAME=	quagga-1.2.4
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://download.savannah.gnu.org/releases/quagga/

CONFLICTS=	frr-[0-9]*

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/quagga/
COMMENT=	Free multithreaded routing daemon software
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		gawk gmake perl pkg-config
USE_LIBTOOL=		YES

TEST_TARGET=		check

PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-exampledir=${PREFIX}/share/examples/quagga
#CONFIGURE_ARGS+=	--enable-pkgsrcrcdir=${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run/zebra
# Requires libcares
CONFIGURE_ARGS+=	--disable-nhrpd

BUILD_DEFS+=		VARBASE

CONFLICTS+=		zebra-[0-9]*

PLIST_SRC=		${WRKDIR}/PLIST
PLIST_CAT=		# empty

INFO_FILES=	yes

RCD_SCRIPTS=		zebra bgpd ospfd ripd
PKG_GROUPS=		quagga
PKG_USERS=		quagga:quagga

PKG_SYSCONFDIR_PERMS=	quagga quagga 750
# log_syslog.conf is used as a template for each config file
.for file in vtysh.conf zebra.conf bgpd.conf ospfd.conf ripd.conf
CONF_FILES_PERMS+=	${PREFIX}/share/examples/quagga/log_syslog.conf \
			${PKG_SYSCONFDIR}/${file} quagga quagga 0600
.endfor

.include "options.mk"

.if ${INIT_SYSTEM} == "smf"
BUILD_DIRS=		. solaris
SMF_INSTANCES=		bgp ospf ospf6 rip ripng zebra
SMF_METHODS=		quagga
SMF_METHOD_SRC.quagga=	${WRKSRC}/solaris/quagga.init
FILES_SUBST+=		PKG_SMF_METHOD_DIR=${PKG_SMF_METHOD_DIR}
.endif

PLIST_CAT+=		${PKGDIR}/PLIST

LIBS+=			${LDFLAGS}

.for script in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${script}?=	${WRKSRC}/pkgsrc/${script}.sh
.endfor

INSTALLATION_DIRS+=	share/doc/quagga
INSTALLATION_DIRS+=	share/doc/quagga/mpls

post-install:
	${CHMOD} a+r ${DESTDIR}${PREFIX}/share/examples/quagga/*
	${INSTALL_DATA} ${FILESDIR}/log_syslog.conf ${DESTDIR}${PREFIX}/share/examples/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/BGP-TypeCode ${DESTDIR}${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/draft-zebra-00.txt ${DESTDIR}${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/mpls/* ${DESTDIR}${PREFIX}/share/doc/quagga/mpls
	${CAT} ${PLIST_CAT} > ${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} share/doc/quagga -type f -print ) >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
