# $NetBSD: Makefile,v 1.33.4.1 2006/12/07 15:01:25 salo Exp $

DISTNAME=		#defined
PKGNAME=		fprot-workstation-bin-${FPVER}
CATEGORIES=		security

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/home_use/bsd/
COMMENT=		F-prot antivirus for home users

DEPENDS+=		p5-libwww>=5.69:../../www/p5-libwww
DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

PKG_INSTALLATION_TYPES= overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-[2-9]*-x86_64 \
			Linux-*-i386 SunOS-*-sparc
RESTRICTED=		Redistribution not permitted
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
LICENSE=		fprot-workstation-license

WRKSRC=			${WRKDIR}/f-prot
NO_BUILD=		yes
USE_TOOLS+=		perl:run

FPVER=			4.6.7
DATDIR=			${PREFIX}/share/fprot-workstation-bin
DOCDIR=			${PREFIX}/share/doc/fprot-workstation-bin
FPDIR=			${PREFIX}/libexec/fprot-workstation-bin
CONF_FILES=		${DATDIR}/MACRO.DEF ${FPDIR}/MACRO.DEF
CONF_FILES+=		${DATDIR}/SIGN.DEF ${FPDIR}/SIGN.DEF
CONF_FILES+=		${DATDIR}/SIGN2.DEF ${FPDIR}/SIGN2.DEF
REQD_DIRS+=		${FPDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MASTER_SITES=		ftp://ftp.f-prot.com/pub/bsd/
DISTNAME=		fp-netbsd-ws-${FPVER}
.endif

.if ${OPSYS} == "Linux"
MASTER_SITES=		ftp://ftp.f-prot.com/pub/linux/
DISTNAME=		fp-linux-ws-${FPVER}
.endif

.if ${OPSYS} == "SunOS"
MASTER_SITES=		ftp://ftp.f-prot.com/pub/solaris/
DISTNAME=		fp-solaris-sparc-ws-${FPVER}
.endif

.if (${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "x86_64")
DEPENDS+=	netbsd32_compat16>=1.0:../../emulators/netbsd32_compat16
.endif

DIST_SUBDIR=		${PKGBASE}-20061204

SUBST_CLASSES+=		f-prot
SUBST_MESSAGE.f-prot=	Configuring f-prot location.
SUBST_STAGE.f-prot=	post-patch
SUBST_FILES.f-prot=	f-prot.sh
SUBST_SED.f-prot=	-e "s,^exec \`.*\`,exec ${FPDIR}/f-prot,g"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Configuring default paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	tools/check-updates.pl
SUBST_SED.paths=	-e "s,XXXFPDIRXXX,${FPDIR},"
SUBST_SED.paths+=	-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/f-prot.sh ${PREFIX}/bin/f-prot
	${INSTALL_SCRIPT} ${WRKSRC}/tools/check-updates.pl ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man_pages/check-updates.pl.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man_pages/f-prot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DATDIR}
	${INSTALL_DATA} ${WRKSRC}/*.DEF ${DATDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE* ${WRKSRC}/README ${WRKSRC}/CHANGES \
		${WRKSRC}/doc_ws/* ${DOCDIR}
	${INSTALL_PROGRAM_DIR} ${FPDIR}
	${INSTALL_DATA} ${WRKSRC}/ENGLISH.TX0 ${FPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/f-prot ${FPDIR}

.include "../../mk/bsd.pkg.mk"
