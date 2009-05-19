# $NetBSD: Makefile,v 1.40 2009/05/19 08:59:30 wiz Exp $

DISTNAME=		fprot-workstation-bin	# overridden below
PKGNAME=		fprot-workstation-bin-${FPVER}
CATEGORIES=		security
MASTER_SITES=		# empty
DIST_SUBDIR=		${PKGBASE}-20070806
FPVER=			4.6.8

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.f-prot.com/products/home_use/
COMMENT=		F-prot antivirus for home users
LICENSE=		fprot-workstation-license

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DEPENDS+=		p5-libwww>=5.69:../../www/p5-libwww

USE_TOOLS+=		perl:run unzip:run

PKG_INSTALLATION_TYPES= overwrite pkgviews

#EMUL_PLATFORMS+=	linux-i386
EMUL_PLATFORMS+=	netbsd-i386
#EMUL_PLATFORMS+=	solaris-i386
#EMUL_PLATFORMS+=	solaris-sparc
EMUL_MODULES.linux=	base

.include "../../mk/bsd.prefs.mk"

# This following section should be split out into Makefile.${EMUL_PLATFORM}
# files and the appropriate build and installation code added.
#
.if ${EMUL_PLATFORM} == "linux-i386"
MASTER_SITES=		http://files.f-prot.com/files/linux-x86/
DISTNAME=		fp-linux-ws
.elif ${EMUL_PLATFORM} == "solaris-i386"
MASTER_SITES=		http://files.f-prot.com/files/solaris-i386/
DISTNAME=		fp-solaris-i386-ws
.elif ${EMUL_PLATFORM} == "solaris-sparc"
MASTER_SITES=		http://files.f-prot.com/files/solaris-sparc/
DISTNAME=		fp-solaris-sparc-ws
.endif

.if exists(Makefile.${EMUL_PLATFORM})
.  include "Makefile.${EMUL_PLATFORM}"
.else
NO_BUILD=	yes
do-install:	# nothing
.endif

.include "../../mk/bsd.pkg.mk"
