# $NetBSD: Makefile,v 1.21 2001/07/16 13:57:25 wiz Exp $
#

DISTNAME=	hylafax-4.1
PKGNAME=	hylafax-4.1nb1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.hylafax.org/source/ \
		ftp://ftp.leo.org/pub/comp/os/unix/networking/fax/hylafax/source/

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
