# $NetBSD: Makefile,v 1.13 2004/10/13 20:11:16 ben Exp $
#

DISTNAME=		#defined
PKGNAME=		fprot-workstation-bin-4.4.7
CATEGORIES=		security

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/home_use/bsd/
COMMENT=		F-prot antivirus for home users

DEPENDS+=		p5-libwww>=5.69:../../www/p5-libwww
DEPENDS+=		unzip-[0-9]*:../../archivers/unzip

PKG_INSTALLATION_TYPES= overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386 SunOS-*-sparc
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
LICENSE=		fprot-workstation-license

WRKSRC=			${WRKDIR}/f-prot
NO_BUILD=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

DATDIR=			${PREFIX}/share/fprot-workstation-bin
DOCDIR=			${PREFIX}/share/doc/fprot-workstation-bin
FPDIR=			${PREFIX}/libexec/fprot-workstation-bin

FILES_SUBST+=		FPDIR=${FPDIR:Q}
FILES_SUBST+=		DATDIR=${DATDIR:Q}

SUPPORT_FILES=          ${DATDIR}/MACRO.DEF ${FPDIR}/MACRO.DEF
SUPPORT_FILES+=         ${DATDIR}/SIGN.DEF ${FPDIR}/SIGN.DEF
SUPPORT_FILES+=         ${DATDIR}/SIGN2.DEF ${FPDIR}/SIGN2.DEF
OWN_DIRS=               ${FPDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MASTER_SITES=		ftp://ftp.f-prot.com/pub/bsd/
DISTNAME=		fp-netbsd-ws-${PKGVERSION}
.endif

.if ${OPSYS} == "Linux"
MASTER_SITES=		ftp://ftp.f-prot.com/pub/linux/
DISTNAME=		fp-linux-ws-${PKGVERSION}
.endif

.if ${OPSYS} == "SunOS"
MASTER_SITES=		ftp://ftp.f-prot.com/pub/solaris/
DISTNAME=		fp-solaris-sparc-ws-${PKGVERSION}
.endif

DIST_SUBDIR=		${DISTNAME}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Configuring default paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths+=	${WRKSRC}/tools/check-updates.pl \
			${WRKSRC}/f-prot.sh
SUBST_SED.paths=	-e "s,/usr/local/f-prot,${FPDIR},g" \
			-e "s,/usr/bin/perl,${PREFIX}/bin/perl,g"

.if ${OPSYS} == "NetBSD"
pre-install:
	${RM} -f ${WRKSRC}/doc_ws/norm_scan.gif
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/f-prot.sh ${PREFIX}/bin/f-prot
	${INSTALL_SCRIPT} ${WRKSRC}/tools/check-updates.pl ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man_pages/check-updates.pl.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man_pages/f-prot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${DATDIR}
	${INSTALL_DATA} ${WRKSRC}/*.DEF ${DATDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${WRKSRC}/README ${WRKSRC}/CHANGES \
		${WRKSRC}/doc_ws/* ${DOCDIR}
	${INSTALL_PROGRAM_DIR} ${FPDIR}
	${INSTALL_DATA} ${WRKSRC}/ENGLISH.TX0 ${FPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/f-prot ${FPDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
