# $NetBSD: Makefile,v 1.32 2006/09/04 08:47:17 martti Exp $

DISTNAME=	LPRng-3.8.28
PKGNAME=	LPRng-core-3.8.28
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lprng.com/pub/LPRng/LPRng/ \
		http://www.lprng.com/DISTRIB/LPRng/ \
		http://lprng.sourceforge.net/DISTRIB/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	Enhanced Printer Spooler

CONFLICTS+=		cups-[0-9]*

USE_TOOLS+=		chgrp chown gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-lpd_perms_path=${LPD_PERMS_PATH:Q}
CONFIGURE_ARGS+=	--with-lpd_printcap_path=${LPD_PRINTCAP_PATH:Q}
CONFIGURE_ARGS+=	--with-printcap_path=${PRINTCAP_PATH:Q}
CONFIGURE_ARGS+=	--with-filterdir=${FILTER_DIR:Q}
CONFIGURE_ARGS+=	--with-filter_path=${FILTER_PATH:Q}
CONFIGURE_ARGS+=	--with-ld_library_path=${FILTER_LD_PATH:Q}
CONFIGURE_ENV+=		CHGRP=${TOOLS_CHGRP:Q}
CONFIGURE_ENV+=		CHOWN=${TOOLS_CHOWN:Q}

.include "options.mk"

# Look for printer configuration files firstly in /etc, then ${PREFIX}/etc.
#
LPD_PERMS_PATH=		${PKG_SYSCONFDIR}/lpd/lpd.perms
LPD_PRINTCAP_PATH=	${PKG_SYSCONFDIR}/printcap
PRINTCAP_PATH=		${PKG_SYSCONFDIR}/printcap
FILTER_DIR=		${PREFIX}/libexec/LPRng
FILTER_LD_PATH=		/usr/lib:${PREFIX}/lib:/usr/local/lib
FILTER_PATH=		${FILTER_DIR}:/sbin:/usr/sbin:/bin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:/usr/local/sbin:/usr/local/bin

MAKE_ENV+=		POSTINSTALL="NO"

EXAMPLESDIR=		${PREFIX}/share/examples/LPRng
RCD_SCRIPTS=		LPRng
OWN_DIRS+=		${PKG_SYSCONFDIR}/lpd
CONF_FILES+=		${EXAMPLESDIR}/lpd.conf ${PKG_SYSCONFDIR}/lpd/lpd.conf
CONF_FILES+=		${EXAMPLESDIR}/lpd.perms ${PKG_SYSCONFDIR}/lpd/lpd.perms
CONF_FILES+=		${EXAMPLESDIR}/printcap ${PKG_SYSCONFDIR}/printcap

pre-patch:
	${MV} ${WRKSRC:Q}/man/lpd.conf.n ${WRKSRC:Q}/man/lpd.conf.n.in

post-configure:
	${SED}	-e s,@FILTER_LD_PATH@,${FILTER_LD_PATH:Q},g		\
		-e s,@FILTER_PATH@,${FILTER_PATH:Q},g			\
		-e s,@LPD_PRINTCAP_PATH@,${LPD_PRINTCAP_PATH:Q},g	\
		-e s,@LPD_PERMS_PATH@,${LPD_PERMS_PATH:Q},g		\
		-e s,@PRINTCAP_PATH@,${PRINTCAP_PATH:Q},g		\
		-e s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:Q},g		\
		${WRKSRC:Q}/man/lpd.conf.n.in > ${WRKSRC:Q}/man/lpd.conf.n

pre-install:
	${SED}	-e s,@PREFIX@,${PREFIX:Q},g				\
		${FILESDIR:Q}/LPRng.sh > ${WRKDIR:Q}/LPRng.sh

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lpd.conf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/lpd.perms ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/printcap ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
