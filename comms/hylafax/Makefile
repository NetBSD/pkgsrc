# $NetBSD: Makefile,v 1.17 2001/04/23 15:06:10 abs Exp $
#

DISTNAME=	hylafax-4.1beta3
PKGNAME=	hylafax-4.1b3
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/ \
		ftp://ftp.sisis.de/pub/hylafax/source/ \
		ftp://ftp.uni-bremen.de/pub/mirrors/ftp.hylafax.org/pub/hylafax/source/

PATCH_SITES=   http://www.hylafax.org/patches/
PATCHFILES=    hfaxd-vulnerability.patch

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.hylafax.org/
COMMENT=	Telecommunication and fax server system

DEPENDS+=	tiff-*:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	mawk>=1.2.2:../../lang/mawk
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript

DIST_SUBDIR=	hylafax

CONFLICTS=	mgetty-*

FAXUSER?=	uucp
FAXGROUP?=	dialer

HAS_CONFIGURE=	YES
CONFIGURE_ENV=	PREFIX="${PREFIX}" FAXUID="${FAXUSER}" FAXGID="${FAXGROUP}"
CONFIGURE_ARGS=	--with-MAKE=${MAKE_PROGRAM} --with-INSTALL="" --nointeractive
MANCOMPRESSED=	yes

SUID_EXES=	${PREFIX}/libexec/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-build:
	${SED} -e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
	    -e 's#@PREFIX@#${PREFIX}#g' \
	    <${FILESDIR}/hylafax.sh >${WRKDIR}/hylafax.sh; \

post-install:
	${CHOWN} ${FAXUSER} ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}
	${INSTALL_SCRIPT} ${WRKDIR}/hylafax.sh ${PREFIX}/etc/rc.d/hylafax

.include "../../mk/bsd.pkg.mk"
