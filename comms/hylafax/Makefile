# $NetBSD: Makefile,v 1.13 2000/09/05 12:50:52 rh Exp $
#

DISTNAME=	hylafax-4.1beta2
PKGNAME=	hylafax-4.1b2nb2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/ \
		ftp://ftp.sisis.de/pub/hylafax/source/ \
		ftp://ftp.uni-bremen.de/pub/mirrors/ftp.hylafax.org/pub/hylafax/source/

PATCH_SITES=	http://www.hylafax.org/patches/
PATCHFILES=	tiff-3.5-interfaces.patch

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.hylafax.org/

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
CONFIGURE_ARGS=	--with-MAKE=${MAKE_PROGRAM} --with-INSTALL=""
MANCOMPRESSED=	yes

SUID_EXES=	${PREFIX}/libexec/faxgetty ${PREFIX}/sbin/faxq \
		${PREFIX}/bin/faxrm ${PREFIX}/bin/faxalter

post-install:
	${CHOWN} ${FAXUSER} ${SUID_EXES}
	${CHMOD} 4555 ${SUID_EXES}

post-build:
	${SED} -e 's#@SSH_CONF_DIR@#${SSH_CONF_DIR}#g' \
	    -e 's#@PREFIX@#${PREFIX}#g' \
	    <${FILESDIR}/hylafax.sh >${WRKDIR}/hylafax.sh; \

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/hylafax.sh ${PREFIX}/etc/rc.d/hylafax.sh

.include "../../mk/bsd.pkg.mk"
