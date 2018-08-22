# $NetBSD: Makefile,v 1.60 2018/08/22 09:46:06 wiz Exp $
#

DISTNAME=	quagga-1.2.4
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.savannah.gnu.org/releases/quagga/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/quagga/
COMMENT=	Free multithreaded routing daemon software
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		gawk gmake perl
USE_LIBTOOL=		YES

TEST_TARGET=		check

PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-exampledir=${PREFIX}/share/examples/quagga
#CONFIGURE_ARGS+=	--enable-pkgsrcrcdir=${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run/zebra

CONFLICTS+=		zebra-[0-9]*

PLIST_SRC=		${WRKDIR}/PLIST
PLIST_CAT=		# empty

INFO_FILES=	yes

RCD_SCRIPTS=		zebra bgpd ospfd ripd
PKG_GROUPS=		quagga
PKG_USERS=		quagga:quagga

PKG_SYSCONFDIR_PERMS=	quagga quagga 750
# log_syslog.conf is used as a template for each config file
.for _file_ in vtysh.conf zebra.conf bgpd.conf ospfd.conf ripd.conf
CONF_FILES_PERMS+=	${PREFIX}/share/examples/quagga/log_syslog.conf \
			${PKG_SYSCONFDIR}/${_file_} quagga quagga 0600
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

.for _script_ in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${_script_}?=	${WRKSRC}/pkgsrc/${_script_}.sh
.endfor

post-install:
	@${CHMOD} a+r ${DESTDIR}${PREFIX}/share/examples/quagga/*
	${INSTALL_DATA} ${FILESDIR}/log_syslog.conf ${DESTDIR}${PREFIX}/share/examples/quagga
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/quagga
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/quagga/mpls
	${INSTALL_DATA} ${WRKSRC}/doc/BGP-TypeCode ${DESTDIR}${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/draft-zebra-00.txt ${DESTDIR}${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/mpls/* ${DESTDIR}${PREFIX}/share/doc/quagga/mpls
	${CAT} ${PLIST_CAT} > ${PLIST_SRC}
	(cd ${DESTDIR}${PREFIX}; ${FIND} share/doc/quagga -type f -print ) >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
