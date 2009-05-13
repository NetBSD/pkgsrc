# $NetBSD: Makefile,v 1.8 2009/05/13 10:02:40 hasso Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	quagga-0.99.12
CATEGORIES=	net
MASTER_SITES=	http://www.quagga.net/download/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.quagga.net/
COMMENT=	Free multithreaded routing daemon software (fork of zebra)

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl
USE_LIBTOOL=		YES

PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-exampledir=${PREFIX}/share/examples/quagga
#CONFIGURE_ARGS+=	--enable-pkgsrcrcdir=${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/run/zebra

CONFLICTS+=		zebra-[0-9]*

PLIST_SRC=		${WRKDIR}/PLIST
PLIST_CAT=		# empty

INFO_FILES=		# PLIST

RCD_SCRIPTS=		zebra bgpd ospfd ripd
PKG_GROUPS=		quagga
PKG_USERS=		quagga:quagga

# log_syslog.conf is used as a template for each config file
.for _file_ in vtysh.conf zebra.conf bgpd.conf ospfd.conf ripd.conf
CONF_FILES_PERMS+=	${PREFIX}/share/examples/quagga/log_syslog.conf \
			${PKG_SYSCONFDIR}/${_file_} quagga quagga 0600
.endfor

.include "options.mk"

PLIST_CAT+=		${PKGDIR}/PLIST

LIBS+=			${LDFLAGS}

.for _script_ in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${_script_}?=	${WRKSRC}/pkgsrc/${_script_}.sh
.endfor

post-install:
	@${CHMOD} a+r ${PREFIX}/share/examples/quagga/*
	${INSTALL} -d -o quagga -g quagga -m 750 ${PKG_SYSCONFDIR}
	${INSTALL_DATA} ${FILESDIR}/log_syslog.conf ${PREFIX}/share/examples/quagga
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quagga
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/quagga/mpls
	${INSTALL_DATA} ${WRKSRC}/doc/BGP-TypeCode ${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/draft-zebra-00.txt ${PREFIX}/share/doc/quagga
	${INSTALL_DATA} ${WRKSRC}/doc/mpls/* ${PREFIX}/share/doc/quagga/mpls
	${CAT} ${PLIST_CAT} > ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/quagga -type f -print ) >> ${PLIST_SRC}
	(cd ${PREFIX}; ${FIND} share/doc/quagga -type d -print ) | \
		${SED} -e 's/^/@dirrm /' | ${SORT} -r >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
