# $NetBSD: Makefile,v 1.1.1.1 2004/09/22 15:01:35 adrianp Exp $

DISTNAME=	snort-2.2.0
PKGNAME=	${DISTNAME:S/-/-contrib-/}
CATEGORIES=	net security
MASTER_SITES=	http://www.snort.org/dl/ \
		ftp://the.wiretapped.net/pub/security/network-intrusion-detection/snort/ \
		ftp://gd.tuwien.ac.at/infosys/security/snort/dl/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Network Intrusion Detection System (contrib files)

USE_BUILDLINK3=	NO
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_PERL5=	YES

SNORTDIR=	${PREFIX}/share/snort
CONTRIBDIR=	${WRKSRC}/contrib
REPLACE_PERL=	contrib/regen-sidmap contrib/snort-sort.pl \
		contrib/snort2html.pl contrib/snort_stat.pl snortlog

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	contrib/address_config.sh contrib/S99snort
SUBST_SED.paths=	-e "s|/bin/sh|${SH}|g" \
			-e "s|/usr/local/bin|${PREFIX}/bin|g" \
			-e "s|/bin/bash|${SH}|g" \
			-e "s|/usr/local/share/snort/snort.conf|${PKG_SYSCONFDIR}|g" \

do-install:
	${INSTALL_DATA_DIR} ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/S99snort ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/address_config.sh ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/ms_unicode_generator.c ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/mysql.php3 ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/Spade-092200.1.tar.gz ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/Guardian.tar.gz ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/Net-SnortLog-0.1.tar.gz ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/passiveOS.tar.gz ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/perfstats.c ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/pgsql.php3 ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/regen-sidmap ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/snort-sort.pl ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/snort2html.pl ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/snort_stat.pl ${SNORTDIR}
	${INSTALL_SCRIPT} ${CONTRIBDIR}/snortlog ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/snortdb-extra.gz ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/snortnet.tar.gz ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/snortpp.c ${SNORTDIR}
	${INSTALL_DATA} ${CONTRIBDIR}/snortwatch-0.7.tar.gz ${SNORTDIR}

.include "../../mk/bsd.pkg.mk"
